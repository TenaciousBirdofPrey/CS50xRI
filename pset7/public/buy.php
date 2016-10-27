<?php

    // configuration
    require("../includes/config.php");
     if ($_SERVER["REQUEST_METHOD"] == "POST")
     {
         $buy_stock = $_POST['stock'];
         $num_stock = $_POST['num_stock'];
         
         //check both fields
         if (     empty($_POST['stock'])    ||     empty($_POST['num_stock'])            )
         {
             apologize("you must enter both fields");
         }
         
         //check non negative
         if ( $num_stock < 0 )
         {
             apologize("amount of shares must be greater then 0");
         }
         // lookup
         $buy_lookup = lookup($buy_stock);
         //dump($buy_lookup);
         //dump("hi");--dump will print!
         
         // get thier cash total
         $buy_cash = CS50::query("SELECT cash FROM users WHERE id = ?",$_SESSION['id']);
         //dump($buy_cash);
         
         //see if they can afford it
         if ($buy_cash[0]['cash'] < $buy_lookup['price']*$num_stock)
         {
             apologize("sorry bro...you too broke!");
         }
     $buy_it =CS50::query("INSERT INTO portfolio (user_id, symbol, shares)
                          VALUES(?, ?, ?)
                          ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)"
                          ,$_SESSION['id'],  $buy_stock  ,$num_stock );
                          
                          
    $history_buy =CS50::query("INSERT INTO history (user_id, transaction,symbol, shares, price)
                          VALUES(?, ?, ?,?,?)"
                          ,$_SESSION['id'],'BUY',$buy_stock  ,$num_stock,$buy_lookup['price'] );
        redirect("index.php"); 
     }
    render("views_buy.php", [ "title" => "views_buy"]);
    


?>