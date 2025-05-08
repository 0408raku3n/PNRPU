<?php
    @session_start();
        
    $_SESSION['user'] = $_POST['auth_login'];
    $_SESSION['pass'] = $_POST['auth_password'];

    $host = 'localhost';
    $dbname = 'Politician Rating';

    $sql = @new mysqli('localhost', $_SESSION['user'], $_SESSION['pass'], 'PoliticianRating');
    $sql->set_charset('utf8');

    if ($sql->connect_errno)
    {
        header('Location:index.php');
        echo "Error! Try again!";
    }
    else
    {
        header('Location: index2.php');
    }
?>