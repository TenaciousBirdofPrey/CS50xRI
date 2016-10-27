<div class="container">
  <!--<iframe allowfullscreen frameborder="0" height="315" src="https://www.youtube.com/embed/oHg5SJYRHA0?autoplay=1&iv_load_policy=3&rel=0" width="420"></iframe>
  -->
  
portfolio.php
  <table class="table table-striped">
    
    <thead>
      <tr>
        <th>STOCK</th>
        <th>SHARES</th>
        <th>PRICE</th>
        <th>TOTAL</th>
        
        
      </tr>
    </thead>
    <?php
    
    //dump($positions);
    
       
        foreach ($positions as $position)
        {
            print("<tr>");
            print("<td>{$position["symbol"]}</td>");
            print("<td>{$position["shares"]}</td>");
            print("<td>{$position["price"]}</td>");
            
             print("<td>".  number_format( $position["total"] )  ."</td>");
             
             
            print("</tr>");
            
        }

    ?>
</table>
  
    
</div>

