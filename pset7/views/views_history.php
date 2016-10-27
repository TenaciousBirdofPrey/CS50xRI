<div class="container">

  
history.php
  <table class="table table-striped">
    <thead>
      <tr>
        <th>transaction</th>
        <th>DATE</th>
        <th>SYMBOL</th>
        <th>SHARES</th>
        <th>PRICE</th>
        
      </tr>
    </thead>
    <?php
    
    //dump($master_history);
    /*
             [user_id] => 22
            [transaction] => BUY
            [date] => 0000-00-00 00:00:00
            [symbol] => aapl
            [shares] => 1
            [price] => 109
   */ 
       
        foreach ($master_history as $herstory)
        {
            print("<tr>");
            print("<td>{$herstory['transaction']    }</td>");
            print("<td>{$herstory["date"]}</td>");
            print("<td>{$herstory["symbol"]}</td>");
           
            print("<td>{$herstory["shares"]}</td>");
            print("<td>{$herstory["price"]}</td>");
            print("</tr>");
            
        }

    ?>
</table>
  
    
</div>
