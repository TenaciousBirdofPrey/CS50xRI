this is sell_form

                                             

<form action="sell.php" method="POST"/>
 <fieldset>
        <div class="form-group">
   
    <label>Select a stock to sell </label>
    <select name="select_stock">
        
        <?php
       
        foreach ($stocks_owned as $stock)
        {
        echo "<option value = \"".$stock['symbol']."\">".$stock['symbol']. "</option>";  
        }
        ?>

    </select>
    
    <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
    </div>
</form>    






        
       