/*
Name: Ellie Thach
KUID: 3139476
LAB Session: 06
LAB Assignment Number: 06
Program Description: This javascript file has the functions for the buttons in practice2.html (changing rgb values) and practice3.html (checking passwords).
Collaborators: None
*/

function alert_paragraph_color() {
    var border_R = document.getElementById("border_R").value;
    var border_G = document.getElementById("border_G").value;
    var border_B = document.getElementById("border_B").value;
    var border_width = document.getElementById("border_width").value;
    var bg_R = document.getElementById("bg_R").value;
    var bg_G = document.getElementById("bg_G").value;
    var bg_B = document.getElementById("bg_B").value;

    const element = document.getElementById("paragraph");

    element.style.borderColor = `rgb(${border_R},${border_G},${border_B})`; // changes border color with input from html file
    element.style.borderWidth = border_width // changes border width with input from html file
    element.style.backgroundColor = `rgb(${bg_R},${bg_G},${bg_B})`; // changes background color with input from html file
}

function validate() {
    var password1 = document.getElementById("password1").value;
    var password2 = document.getElementById("password2").value;

    if (password1.length < 8) {
        alert("The length of the first password is less than 8 letters.") // if password 1's length is less than 8, it gives the user an alert
    } else if (password2.length < 8) {
        alert("The length of the second password is less than 8 letters.") // if password 2's length is less than 8, it gives the user an alert
    } else if (password1 != password2) {
        alert("The two passwords don't match.") // if password 1 and password 2 have different values, it gives the user an alert
    } else {
        alert("Everything is good! Your passwords match.")
    }
}