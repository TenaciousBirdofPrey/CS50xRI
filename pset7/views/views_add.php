
add money to your bank<br>

you have <br>
<?php
print "$". number_format(  $balance[0]['cash']  ) ;
?><br>
 in the bank.<br>
<form action="add.php" method="post">
    <fieldset>
        
        <div class="form-group">
            <input class="form-control" name="add_cash" placeholder="amount to deposit" type="number"/>
        </div>
        
        
        
        
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                add!
            </button>
        </div>