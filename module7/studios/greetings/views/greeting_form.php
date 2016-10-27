<!--https://www.youtube.com/watch?v=IVl5GPpMJsY-->
<h1>Build Your Greeting cuz greeting_form is called!</h1>
<form action="greet.php" method="POST"/>
    <label>Your name:</label>
    <input type="text" name="recipient_name" />
    <br/>
    <label>Select a greeting:</label>
    <select name="select_greeting">
        
        <?php
        $greetings =CS50::query("SELECT text FROM greetings");
        foreach ($greetings as $greet)
        {
        echo "<option value = \"".$greet['text']."\">".$greet['text']. "</option>";  
        }
        ?>

    </select>
    <label>Or create your own:</label>
    <input type="text" name="custom_greeting" />
    <br/>
    <input type="submit"/>
</form>

<?php

var_dump($greetings);


?>