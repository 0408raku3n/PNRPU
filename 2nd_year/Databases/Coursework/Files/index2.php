<?php
@session_start();
    $sql = @new mysqli('localhost', $_SESSION['user'], $_SESSION['pass'], 'PoliticianRating');
    $sql->set_charset('utf8');

?>
<html>
    <head>
        <meta charset = "UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>
            Politician Rating
        </title>
        <link href="styles/style.css" rel="stylesheet" type="text/css" />
    </head>
    <body>
        <div class = "page">
            <form action = "queries.php" method = "post">
                    <div class = "sidemenu">
                        <?php
                        if($_SESSION['user'] == 'admin' or $_SESSION['user'] == 'root')
                        {
                            echo '<button type = "submit" class = "button1" name = "base" value = 1 title = "Создание всех таблиц">CREATE</button>';
                            echo '<button type = "submit" class = "button1" name = "base" value = 2 title = "Удаление всех таблиц">DROP</button>';
                            echo '<button type = "submit" class = "button1" name = "base" value = 3 title = "Добавление данных в таблицы">INSERT</button>';
                            echo '<button type = "submit" class = "button1" name = "interviewee" value = 1 title = "Добавить новых опрашиваемых (и их голосов)">ADD INTERVIEWEE</button>';
                            echo '<button type = "submit" class = "button1" name = "interviewee" value = 2 title = "Удалить опрашиваемого">DELETE INTERVIEWEE</button>';
                        }
                        elseif ($_SESSION['user'] == 'superuser')
                        {
                            echo '<button type = "submit" class = "button1" name = "interviewee" value = 1 title = "Добавить новых опрашиваемых (и их голосов)">ADD INTERVIEWEE</button>';
                            echo '<button type = "submit" class = "button1" name = "interviewee" value = 2 title = "Удалить опрашиваемого">DELETE INTERVIEWEE</button>';
                        }
                        ?>
                        
                        <div class = "dropdown" style = "margin-bottom: 270px;">
                            <button class = "dropbtn" disabled>SHOW VIEWS</button>
                            <div class = "dropdown-content">
                                <button type = "submit" class = "button1" name = "show" value = 1 title = 'Отобразить список субъектов'>FEDERAL SUBJECTS</button>
                                <button type = "submit" class = "button1" name = "show" value = 2 title = 'Отобразить список социальных статусов'>SOCIAL STATUSES</button>
                                <button type = "submit" class = "button1" name = "show" value = 3 title = 'Отобразить список опрашиваемых'>INTERVIEWEES</button>
                                <button type = "submit" class = "button1" name = "show" value = 4 title = 'Отобразить список политиков'>POLITICIANS</button>
                                <button type = "submit" class = "button1" name = "show" value = 5 title = 'Отобразить список выполненных наказов'>IMPLEMENTED ORDERS</button>
                                <button type = "submit" class = "button1" name = "show" value = 6 title = 'Отобразить список голосов опрашиваемых'>VOTES OF INTERVIEWEES</button>
                            </div>
                            </button>
                        </div>
                        <div class = "dropdown">
                            <button class = "dropbtn" disabled>SHOW RATING</button>
                            <div class = "dropdown-content">
                                <button type = "submit" class = "button1" name = "rating" value = 1 title = 'Отобразить общий рейтинг'>RATING</button>
                                <button type = "submit" class = "button1" name = "rating" value = 2 title = 'Отобразить 10 самых популярных политиков и их целевые категории граждан'>TOP-10 POLITICIANS</button>
                            </div>
                            </button>
                        </div>
                        <div><button type = "submit" class = "button2" name = "exit" title = "Выйти из системы">EXIT</button></div>
                    </div>
            </form>
        </div>
    </body>
</html>


     