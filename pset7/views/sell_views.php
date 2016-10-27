
<div class="container">

  

  <table class="table table-striped">
    <thead>
      <tr>
        <th>SYMBOL</th>
        <th>NAME</th>
        <th>PRICE</th>
        <th>SHARES</th>
        <th>EARNINGS</th>
       
        
      </tr>
    </thead>
    <?php
    
    
    
       

            print("<tr>");
            print("<td>{$sale_lookup["symbol"]}</td>");
            print("<td>{$sale_lookup["name"]}</td>");
            print("<td>{$sale_lookup["price"]}</td>");
            print("<td>{$shares_portfolio[0]["shares"]}</td>");
            
             print("<td>".  number_format( $earnings )  ."</td>");
             
             
            print("</tr>");
            


    ?>
</table>


