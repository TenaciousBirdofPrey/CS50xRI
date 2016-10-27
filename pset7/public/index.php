<?php

    // configuration
    require("../includes/config.php"); 

    // render portfolio
    //dump($_SESSION["id"]);
    
    $id = $_SESSION["id"];
    
    
    $rows = CS50::query("SELECT * FROM portfolio WHERE user_id = ?",$_SESSION["id"] );
    //dump($rows);//--succesfully prints all stocks in portfolio
    
    
    
    $positions = [];
    
    
    

    foreach ($rows as $row)
    {
    $stock = lookup($row["symbol"]);
    if ($stock !== false)
    {
        $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
            "total" => $stock["price"]*$row["shares"]
        ];
    }
    }
    
    
    
    
    
    
    
    
    //dump($positions);//-- only contains first associative arrays
    
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);

    
   
 
?>
