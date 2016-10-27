<?php

require("../includes/helpers.php");

//print "Hi ".$_POST["recipient_name"]. " How are you\n";------test of $_POST

// for debugging, uncomment the line below so you can see what you're working with in $_POST
 var_dump($_POST);


// extract the $_POST dictionary into local variables (e.g. $recipient_name, $select_greeting, etc)
extract($_POST);

print "from extract recipient_name:".$recipient_name. "<br>";
print "from extract select_greeting:".$select_greeting. "<br>"; 
print "from extract custom_greeting:".$custom_greeting. "<br>"; 

// VALIDATION ----------------------------------------------

// if the user didn't type their name, redirect back to the form
if (empty($recipient_name))
{
    header("Location: index.php");
}



// DETERMINE GREETING TEXT -------------------------------

// decide what the greeting text (e.g. "What is up") should be. 
// by default, use whatever was chosen from the <select> menu
$greeting_text = $select_greeting;
print "after assignment greeting_text:".$greeting_text. "<br>"; 




// TODO 
// if the user provided a custom greeting,
//  -- overwrite $greeting_text to be the custom greeting instead
//  -- and also add the custom greeting as a new row to the database 
//          -- to do this, simply pass it to the create_new_greeting() function from helpers.php

if (!empty($custom_greeting))
{
    $greeting_text =$custom_greeting;
    CS50::query("INSERT INTO greetings (text) VALUES (?)",$custom_greeting);
    CS50::query("UPDATE greetings
                SET num_times = num_times+1
                WHERE text = ? ",$greeting_text);
                
                
    print "in !empty greeting_text:".$greeting_text. "<br>"; 
}
print "post !empty greeting_text:".$greeting_text. "<br>";
CS50::query("UPDATE greetings
            SET num_times = num_times+1
            WHERE text = ? ",$greeting_text);
//CS50::query("SELECT text FROM greetings");

// UPDATE `num_times` ---------------------------------------

// TODO
// increment the `num_times` field in this greeting and update the database. 3 steps:

// 1. get this greeting (the one whose `text` value matches $greeting_text) from the database

// 2. figure out what the new `num_times` value should be, and store it in the local variable below
$new_num_times = 0; // replace the 0. keep this variable around because you'll need it later

// 3. update the database so that this greeting entry has the correct `num_times` value




// RENDER STUFF -------------------------------------------

render("header.php", ["title" => $greeting_text]);

$data = [
    "num_times" => $new_num_times, 
    // TODO 
    // what else do we need to pass over to greeting_display.php?
];
render("greeting_display.php", $data);

render("footer.php");

?>
