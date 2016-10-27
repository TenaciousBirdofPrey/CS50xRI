<?php

    require(__DIR__ . "/../includes/config.php");
    

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    // takes geo,replaces commas with spaces and splits into an array on empty spaces
    $geo = $_GET["geo"];
    $geo2 = str_replace(","," ", $geo);
    $geo3 = explode(" ", $geo2);
    $count = count($geo3);

   //var_dump($geo3);
   //var_dump($count);
   $len_geo3 = strlen($geo3[0]);
   //var_dump($len_geo3);
   
  //breaks into two approaches depending on num elements in geo3
  //var_dump($count);
  
 
   //if enters zip code
   if (is_numeric($geo3[0]))
        {
            //print("sup dog");
            //var_dump($geo3[0]);
            $places =CS50:: query("SELECT *
                            FROM places 
                            WHERE  postal_code LIKE ?",
                            $geo3[0]."%"
                            );
        }
   else
   {
       $places =CS50::query("SELECT *
                            FROM places
                            WHERE place_name LIKE ?", $geo."%");
   }
    
        
  /*  
    
    //enters MA or TX etc
    if ($len_geo3 == 2)
        {
            //print("ma or tx");    
            $places =CS50:: query("SELECT *
                        FROM places 
                        WHERE admin_code1 LIKE ?",
                        strtoupper($geo3[0])."%"
                        );
        } 
        
     
        
        
        
        
        
        
    /*
    // enters city
    else 
        {
            $places =CS50:: query("SELECT *
                        FROM places 
                        WHERE place_name LIKE ?",
                        $geo3[0]."%"
                        );
        }
  
 /* 
  if ($count == 1)
        {
         
         //var_dump($count);
        //if they are entering a zip code
       

       
    
    
        //enters town name
        else   
       
        }
        /*
        //enters state name  
        if (empty($places))    
        {
        $places =CS50:: query("SELECT *
                        FROM places 
                        WHERE admin_name1 LIKE ?",
                        $geo3[0]."%"
                        );
                       
       }
       */
 /*     
    elseif($count > 1)
    {

    	
    	$places = CS50:: query("SELECT *
    	                        FROM places 
    	                        WHERE MATCH(postal_code, place_name, admin_name1, admin_code1)
    	                        AGAINST (?)", $geo);
    }   
        

   
  


/*
    else //if they enter Jacksonville, NC
    if ($len_geo > 2)
       {
        $cityStates = explode(",",$geo);
        var_dump($cityStates);
        $lencS = count($cityStates);
        
            for ($i = 0; $i<$lencS;$i++)
                {
                $clean = trim($cityStates[$i]," ");    
                $places =CS50:: query("SELECT *
                        FROM places 
                        WHERE place_name LIKE ?",
                        $clean."%"
                        );
                }                
       }
  
*/



    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));
    
    
    

?>