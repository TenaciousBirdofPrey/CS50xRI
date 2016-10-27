<?php

    // configuration
    require("../includes/config.php");
     $balance = CS50::query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"] );
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //dump($_POST["add_cash"]);
       
        $deposit = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$_POST["add_cash"],$_SESSION["id"]);
        $balance = CS50::query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"] );
        $_POST["add_cash"]=0;
        render("views_add.php", ["title" => "views_add","balance"=> $balance]);
    }
    
    
  
 
//dump($balance);

    
    render("views_add.php", ["title" => "views_add","balance"=> $balance]);
?>