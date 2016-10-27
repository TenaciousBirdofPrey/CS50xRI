<?php

    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"]=="POST")
    {
    $stock = lookup($_POST["sym"]);
    
    /*
    Array
    (
    [symbol] => AAPL
    [name] => Apple Inc.
    [price] => 105.87
    )
    render("template", ["price" => $stock["price"]]);
    
    */
    //dump($stock);    
    render("views_quote.php", ["title"=>"quote_form", "price"=>$stock["price"],"company"=>$stock["name"] ]  );
    

    }


    render("quote_form.php", ["title" => "quote_form"]);
   
   
   
    
   

   
 
  
   
   


?>
