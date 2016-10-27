<!DOCTYPE html>
<html>
    <head>
        <style>
        table {
        border-collapse: collapse;
        }

        table, td, th {
        border: 1px solid black;
        text-align: center;
        }
   
        </style>
    
    </head>
    
    <body>
    <table>

       
    <?php $var=(int)$_POST["mult"];
    for($j=1;$j<=$var;$j++)
    {
    print"<tr>";
        for($i=1;$i<=$var;$i++)
        {
        print "<td>";
        print $i*$j;
        print "</td>";
        
        }
   print "</tr>";
    }
    
    
    
    ?>
       
    </table>     

    </body>
    
    
</html>