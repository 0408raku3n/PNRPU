<link href="styles/style.css" rel="stylesheet" type="text/css" />
<?php
@session_start();
        $sql = @new mysqli('localhost', $_SESSION['user'], $_SESSION['pass'], 'PoliticianRating');
        $sql->set_charset('utf8');
                if (isset($_POST['submitAdd']))
                {
                        $si = $_POST['surname'];
                        $ni = $_POST['name'];
                        $pi = $_POST['patronymic'];
                        $socst = $_POST['socstatlist'];
                        $g = $_POST['genderlist'];
                        $a = $_POST['age'];
                        $p1 = $_POST['1stpolitician'];
                        $p2 = $_POST['2ndpolitician'];
                        $p3 = $_POST['3rdpolitician'];
                        $p4 = $_POST['4thpolitician'];
                        $p5 = $_POST['5thpolitician'];
                        $sql->query("CALL Add_interviewee('$si', '$ni', '$pi', $socst, $g, $a, $p1, $p2, $p3, $p4, $p5)");
                        echo '<div class = "print">
                        <div class = "item"
                        <p>Данные успешно вставлены!</p>
                        </div>
                        </div>>';                
                }
                if (isset($_POST['submitDelete']))
                {
                    $id = $_POST['interviewee'];
                            $sql->query("CALL Delete_interviewee($id)");
                            echo '<div class = "print">
                            <div class = "item"
                            <p>Данные успешно удалены!</p>
                            </div>
                            </div>>';
                }
?>