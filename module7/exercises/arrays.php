<?php

$orders = readline("how many orders?\n");
$ord = (int)$orders;

$names=[];


for ($i=0;$i<$ord;$i++)
{
    $name = readline("name?\n");
    array_push($names,name);
    $food=readline("food?\n");
    array_push($foods,food);
   
}


print "Ok so we have\n";

for ($y=0;$y<$ord;$y++)
{
    print  names($y)."ordered ".foods($y);
}






?>