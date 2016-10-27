<?php

    // configuration
    require("../includes/config.php"); 
    
    // update history with each buy
    //update history with each sell
    //print history
     $master_history = CS50::query("SELECT * FROM history WHERE user_id = ?",$_SESSION["id"] );
    
    render("views_history.php", [ "title" => "views_history","master_history"=>$master_history]);

    
   
 
?>
