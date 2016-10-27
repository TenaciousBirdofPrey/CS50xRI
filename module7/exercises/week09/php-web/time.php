<?php 
date_default_timezone_set('US/Eastern');
$time = date('H:i:s',time());
?>

<!DOCTYPE html>
<html>
    <head>
        <title> The current time on Providence RI</title>
    </head>
    <body>
    The current time in providence is <?= $time?>.
    </body>
</html>