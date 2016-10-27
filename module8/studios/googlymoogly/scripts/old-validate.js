//this is the old attempt!

// first we get a bunch of DOM elements that we will need:

// the form
var form = document.getElementById("form-google");

// the div container that holds stuff relating to the username field
var usernameContainer = document.getElementById("field-username");

// the text input where the user shold type their name
var usernameInput = usernameContainer.querySelector("input"); // the querySelector() function gives us the first <input> child element of usernameContainer

// the div container that holds stuff relating to the search ("q") field
var searchContainer = document.getElementById("field-search"); // TODO something similar to usernameContainer

// the text input where the user types their search query 
var searchInput = searchContainer.querySelector("input"); // TODO something similar to usernameInput



// set a function that will be executed every time the form is submitted
form.onsubmit = validate;


/**
 * checks whether the form was correctly filled out
 * returns true if the form is valid and the HTTP request should be sent,
 * otherwise returns false, in which case the request will not be sent.
 * 
 * also updates the form to display feedback for the user, if it was not valid
 */
function validate(event) {
    
    // uncomment the line below for debugging. Prevents the request from being sent, so you don't annoyingly have to go to google and back every time while testing
    event.preventDefault();
    
    // clear any old feedback on the username field, then recheck the username's validity
    clearFeedback(usernameContainer);
    var username = usernameInput.value;
    var usernameIsValid = username.length > 0;
    if (usernameIsValid == 0) {
        giveFeedback(usernameContainer, "You must tell me your name!");
    }
    
    // clear any old feedback on the search field, then recheck the search query's validity
    // TODO
    clearFeedback(searchContainer);
    var search = searchInput.value;
    var searchIsValid = search.length > 0;
    if (searchIsValid == false) {
        giveFeedback(searchContainer, "You must enter a search");
    }

    //var formIsValid = usernameIsValid; // TODO FIXME the form should only be valid if BOTH the username AND THE SEARCH QUERY are valid
    if (searchIsValid == true  && usernameIsValid == true){
        return formIsValid;
    }
    else{
        return false;
    }
    
    
    //return formIsValid;
};


/**
 * Given a string, returns an array of all the characters in the string that are "not allowed", based
 * on matching against another string, availableChars. Any characters that are not present in availableChars
 * are not allowed.
 */
function invalidChars(str, availableChars) {
    
    // an array to hold the answer
    var invalids = [];
    
    // TODO
    // for each character in str...
    //      if that character is not found in availableChars, then add it to invalids
    // HINT: use these functions:
    //      array.indexof()
    //      array.push()
    
    return invalids;
}


/**
 * given a container <div> and an error message, sets the child <label> to display the error message,
 * and sets the child <input> to have the "input-invalid" class so that our CSS will give it a red border
 */
function giveFeedback(container, message) {
    // TODO 
    // HINT: do something similar to clearFeedback() (see below)
    var stextInput = container.querySelector("input");
    stextInput.className = "";
    var feedbackLabel = container.querySelector(".feedback-error");
    feedbackLabel.innerHTML = message;
}


/**
 * given a container <div>, resets the <input> and <label> inside to be "normal", ie not colored red or reporting any errors
 */
function clearFeedback(container) {
    var textInput = container.querySelector(".input");
    textInput.className = "";
    var feedbackLabel = container.querySelector(".feedback-error");
    feedbackLabel.innerHTML = "";
}