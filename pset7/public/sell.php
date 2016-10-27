<?php

   
    require("../includes/config.php");
    $id_sell = $_SESSION["id"];
    
     if ($_SERVER["REQUEST_METHOD"] == "POST")
     {
        if (   empty($_POST["select_stock"]) ) 
        {
            apologize("you must select a stock to sell");
        }
        // make sure POST exists
        //dump($_POST["select_stock"]);
        
        //query lookup() using POST
        $sale_lookup = lookup($_POST["select_stock"]) ;
        //dump($sale_lookup);
       
        // query portfolio using POST and user id. Returns number of shares.
        $shares_portfolio = CS50::query("SELECT shares FROM portfolio WHERE symbol = ? && user_id =?",$_POST["select_stock"],$id_sell );
        //dump($shares_portfolio);
        
        //calculate earnings
        $earnings= $shares_portfolio[0]['shares']*$sale_lookup['price'];
        //dump($earnings);

        //find amount of share sold
       //shares_portfolio  does this
       
        
        //add sales cash  back to total
        $update = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$earnings,$id_sell);
        
         $history_sell =CS50::query("INSERT INTO history (user_id, transaction,symbol, shares, price)
                          VALUES(?, ?, ?,?,?)"
                          ,$_SESSION['id'],'SELL',$sale_lookup['symbol'] ,$shares_portfolio[0]['shares'],$sale_lookup['price'] );
                          
                          
                          
                       /* result of dump(shares_portfolio) 
                          Array
                        (
                            [0] => Array
                                (
                                [shares] => 1
                                )

                        )
                        //result of dump($sale_lookup)
                        Array
                            (
                             [symbol] => AAPL
                             [name] => Apple Inc.
                             [price] => 108.81
                            )
                        */
        
        
        //remove stock
        $delet_stock =CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?", $id_sell, $_POST["select_stock"] );
        
        
        
          render("sell_views.php", ["title" => "sell_views",
                                    "sale_lookup"=>$sale_lookup,
                                    "shares_portfolio"=>$shares_portfolio,
                                    "earnings"=>$earnings]);
         
     }
     
     
     
     
    
    $stocks_owned = CS50::query(" SELECT symbol FROM portfolio WHERE user_id = $id_sell ");
    //dump($stocks_owned);
    
    //dump($_POST["select_stock"]);
   
    
    render("sell_form.php", [ "title" => "sell_form","stocks_owned"=>$stocks_owned]);

    
         
        /*
        dump($sell_off);
            [0] => Array
        (
            [id] => 3
            [user_id] => 22
            [symbol] => googl
            [shares] => 100
        )
        */
        
       
        
        /* this is lookup()
        dump($sale_lookup);
        [symbol] => IBM
        [name] => International Business Machines
        [price] => 162.39
        */
        
        
        //dump($sell_off[0]["shares"]);  
 
?>