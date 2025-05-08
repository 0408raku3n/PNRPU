<?php
    @session_start();
?>

<html>
    <head>
        <meta charset = "UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>
            Login
        </title>
        <link href="styles/style_login.css" rel="stylesheet" type="text/css" />
    </head>
    <body style = "background-color: gray;">
        <div class = "form_auth">
            <div class = "form_auth_2">
                <p class = "form_auth_head_text">Authorization</p>
                <form class = "form" action = "connect.php" method = "post">
                    <input type = "text" name = "auth_login" placeholder ="Enter login" required>
                    <input type = "password" name = "auth_password" placeholder = "Enter password">
                    <button class = "form_auth_button" type = "submit" name = "form_auth_submit">Login</button>
                </form>
            </div>
        </div>
    </body>
</html>

