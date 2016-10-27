<?php

$pizzas =[
         //"cheese"=>1,
          //"roni"=>2,
         ];
$pizzas["plain"]=3;

for ($i=0;$i<3;$i++)
{
    $type = readline("type?\n");
    $cost = readline("cost?\n");
    $pizzas[$type]=$cost;
}

foreach($pizzas as $topping=>$price)
        {
            print ($topping.":".$price."\n");
            
        }


?>