<link href="styles/style.css" rel="stylesheet" type="text/css" />
<div class = "print">
<div class = "item">
<?php
@session_start();
    $sql = @new mysqli('localhost', $_SESSION['user'], $_SESSION['pass'], 'PoliticianRating');
    $sql->set_charset('utf8');
    $createTable1 = 'CREATE TABLE Interviewee
    (
        ID	SMALLINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        Surname VARCHAR(20) NOT NULL,
        Name VARCHAR(20) NOT NULL,
        Patronymic VARCHAR(20)
    );';

    $createTable2 = 'CREATE TABLE Social_statuses_codifier
    (
        ID TINYINT UNSIGNED PRIMARY KEY,
        Name VARCHAR(20) NOT NULL
    );';

    $createTable3 = 'CREATE TABLE Gender_codifier
    (
        ID TINYINT UNSIGNED PRIMARY KEY,
        Name VARCHAR(7) NOT NULL
    );';

    $createTable4 = 'CREATE TABLE Politician
    (
        ID TINYINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        Surname VARCHAR(20) NOT NULL,
        Name VARCHAR(20) NOT NULL,
        Patronymic VARCHAR(20)
    );';

    $createTable5 = 'CREATE TABLE Federal_subject
    (
        ID TINYINT UNSIGNED PRIMARY KEY,
        Name VARCHAR(35) NOT NULL
    );';

    $createTable6 = 'CREATE TABLE Interviewee_data
    (
        ID_Interviewee SMALLINT UNSIGNED PRIMARY KEY,
        Socstat_code TINYINT UNSIGNED NOT NULL,
        Gender_code TINYINT UNSIGNED NOT NULL,
        Age TINYINT UNSIGNED NOT NULL,
        FOREIGN KEY(ID_Interviewee) REFERENCES Interviewee (ID) ON DELETE CASCADE,
        FOREIGN KEY(Socstat_code) REFERENCES Social_statuses_codifier (ID),
        FOREIGN KEY(Gender_code) REFERENCES Gender_codifier (ID)
    );';

    $createTable7 = 'CREATE TABLE Politician_data
    (
        ID_Politician TINYINT UNSIGNED PRIMARY KEY,
        Fedsubject_code TINYINT UNSIGNED NOT NULL,
        Gender_code TINYINT UNSIGNED NOT NULL,
        Age TINYINT UNSIGNED NOT NULL,
        Rating MEDIUMINT UNSIGNED,
        FOREIGN KEY(ID_Politician) REFERENCES Politician(ID) ON DELETE CASCADE,
        FOREIGN KEY(Fedsubject_code) REFERENCES Federal_subject(ID),
        FOREIGN KEY(Gender_code) REFERENCES Gender_codifier(ID)
    );';

    $createTable8 = 'CREATE TABLE Politician_supporters
    (
        ID_Politician TINYINT UNSIGNED PRIMARY KEY,
        Male_support SMALLINT UNSIGNED,
        Female_support SMALLINT UNSIGNED,
        to20_support SMALLINT UNSIGNED,
        to40_support SMALLINT UNSIGNED,
        to60_support SMALLINT UNSIGNED,
        from60_support SMALLINT UNSIGNED,
        Student_support SMALLINT UNSIGNED,
        Unemployed_support SMALLINT UNSIGNED,
        Employed_support SMALLINT UNSIGNED,
        Pensioner_support SMALLINT UNSIGNED,
        FOREIGN KEY(ID_Politician) REFERENCES Politician_data(ID_Politician)
    )';

    $createTable9= 'CREATE TABLE Orders
    (
        ID_Politician TINYINT UNSIGNED,
        Order_description VARCHAR(100),
        FOREIGN KEY(ID_Politician) REFERENCES Politician(ID),
        PRIMARY KEY(ID_Politician, Order_description)
    );';
    
    $createTable10 = 'CREATE TABLE Poll
    (
        ID_poll SMALLINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        ID_Interviewee SMALLINT UNSIGNED,
        ID_Politician TINYINT UNSIGNED,
        Politician_rating TINYINT UNSIGNED NOT NULL,
        FOREIGN KEY(ID_Interviewee) REFERENCES Interviewee_data(ID_Interviewee) ON DELETE CASCADE,
        FOREIGN KEY(ID_Politician) REFERENCES Politician_data(ID_Politician) ON DELETE CASCADE
    );';

    $createTrigger1 = 'CREATE TRIGGER update_score_after_insert
    AFTER INSERT ON Poll
    FOR EACH ROW
    BEGIN
            DECLARE old_score INT;
            DECLARE new_score INT;
            DECLARE age INT;
            DECLARE socstat INT;
            DECLARE gender INT;
            
            SELECT Rating INTO old_score FROM Politician_data WHERE ID_Politician = NEW.ID_Politician;
            
            SET new_score = old_score + NEW.Politician_rating;
            
            UPDATE Politician_data SET Rating = new_score WHERE ID_Politician = NEW.ID_Politician;
        
            SELECT Interviewee_data.Age, Interviewee_data.Socstat_code, Interviewee_data.Gender_code INTO age, socstat, gender FROM Interviewee_data WHERE Interviewee_data.ID_Interviewee = NEW.ID_Interviewee;
            
            CASE
                WHEN age < 20 THEN 
                UPDATE Politician_supporters SET to20_support = to20_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
                WHEN age >= 20 and age < 40 THEN 
                UPDATE Politician_supporters SET to40_support = to40_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
                WHEN age >= 40 and age < 60 THEN 
                UPDATE Politician_supporters SET to60_support = to60_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
                WHEN age >= 60 THEN 
                UPDATE Politician_supporters SET from60_support = from60_support +NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
            END CASE;
            CASE
                WHEN socstat = 1 THEN
                UPDATE Politician_supporters SET Student_support = Student_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
                WHEN socstat = 2 THEN
                UPDATE Politician_supporters SET Unemployed_support = Unemployed_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
                WHEN socstat = 3 THEN
                UPDATE Politician_supporters SET Employed_support = Employed_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
                WHEN socstat = 4 THEN
                UPDATE Politician_supporters SET Pensioner_support = Pensioner_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
           END CASE;
           CASE
                WHEN gender = 1 THEN
                UPDATE Politician_supporters SET Male_support = Male_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
                WHEN gender = 2 THEN
                UPDATE Politician_supporters SET Female_support = Female_support + NEW.Politician_rating WHERE ID_Politician = NEW.ID_Politician;
               END CASE;
        END;';

    $createProcedure1 = 'CREATE PROCEDURE Add_interviewee (IN si VARCHAR(20), IN ni VARCHAR(20), IN pi VARCHAR(20), IN socst TINYINT UNSIGNED, IN g TINYINT UNSIGNED, IN a TINYINT UNSIGNED,
                                     IN p1 TINYINT UNSIGNED, IN p2 TINYINT UNSIGNED, IN p3 TINYINT UNSIGNED, IN p4 TINYINT UNSIGNED, IN p5 TINYINT UNSIGNED)
    BEGIN
        DECLARE i INT;
        INSERT INTO Interviewee (Surname, Name, Patronymic) VALUES (si, ni, pi);
        SELECT ID INTO i FROM Interviewee WHERE Interviewee.Surname = si LIMIT 1;
        INSERT INTO Interviewee_data VALUES (i, socst, g, a);
        INSERT INTO Poll (ID_Interviewee, ID_Politician, Politician_rating) VALUES (i, p1, 1), (i, p2, 2), (i, p3, 3), (i, p4, 4), (i, p5, 5);
    END;';

    $createProcedure2 = 'CREATE PROCEDURE Delete_interviewee (IN i TINYINT UNSIGNED)
    BEGIN
        DECLARE done INT DEFAULT FALSE;
        DECLARE idp INT;
        DECLARE old_rating INT;
        DECLARE gen_old_rating INT;
        DECLARE new_rating INT;
        DECLARE age INT;
        DECLARE socstat INT;
        DECLARE gender INT;
        
        DECLARE cur CURSOR FOR
            SELECT Poll.ID_Politician
            FROM Poll
            WHERE Poll.ID_Interviewee = i;
        DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
        
        SELECT Interviewee_data.Age, Interviewee_data.Socstat_code, Interviewee_data.Gender_code INTO age, socstat, gender FROM Interviewee_data WHERE Interviewee_data.ID_Interviewee = i;
        
        OPEN cur;
        
        read_loop: LOOP
            FETCH cur INTO idp;
            
            IF done THEN
                LEAVE read_loop;
            END IF;
            
            SELECT Poll.Politician_rating INTO old_rating FROM Poll WHERE Poll.ID_Interviewee = i and Poll.ID_Politician = idp;
            SELECT Politician_data.Rating INTO gen_old_rating FROM Politician_data WHERE Politician_data.ID_Politician = idp;
            SET new_rating = gen_old_rating - old_rating;
            UPDATE Politician_data SET Rating = new_rating WHERE Politician_data.ID_Politician = idp;
            
            CASE
                WHEN age < 20 THEN 
                UPDATE Politician_supporters SET to20_support = to20_support - old_rating WHERE ID_Politician = idp;
                WHEN age >= 20 and age < 40 THEN 
                UPDATE Politician_supporters SET to40_support = to40_support - old_rating WHERE ID_Politician = idp;
                WHEN age >= 40 and age < 60 THEN 
                UPDATE Politician_supporters SET to60_support = to60_support - old_rating WHERE ID_Politician = idp;
                WHEN age >= 60 THEN 
                UPDATE Politician_supporters SET from60_support = from60_support - old_rating WHERE ID_Politician = idp;
            END CASE;
            CASE
                WHEN socstat = 1 THEN
                UPDATE Politician_supporters SET Student_support = Student_support - old_rating WHERE ID_Politician = idp;
                WHEN socstat = 2 THEN
                UPDATE Politician_supporters SET Unemployed_support = Unemployed_support - old_rating WHERE ID_Politician = idp;
                WHEN socstat = 3 THEN
                UPDATE Politician_supporters SET Employed_support = Employed_support - old_rating WHERE ID_Politician = idp;
                WHEN socstat = 4 THEN
                UPDATE Politician_supporters SET Pensioner_support = Pensioner_support - old_rating WHERE ID_Politician = idp;
           END CASE;
           CASE
                WHEN gender = 1 THEN
                UPDATE Politician_supporters SET Male_support = Male_support - old_rating WHERE ID_Politician = idp;
                WHEN gender = 2 THEN
                UPDATE Politician_supporterпоs SET Female_support = Female_support - old_rating WHERE ID_Politician = idp;
               END CASE;
            
        END LOOP;
        
        CLOSE cur;
        
        DELETE FROM Interviewee WHERE Interviewee.ID = i;
    END;';

    $createView1 = 'CREATE VIEW List_of_social_statuses AS
    SELECT ID, Name
    FROM Social_statuses_codifier;';

    $createView2 = 'CREATE VIEW List_of_federal_subjects AS
    SELECT ID, Name
    FROM Federal_subject;';

    $createView3 = 'CREATE VIEW List_of_interviewees AS
    SELECT	Interviewee_data.ID_Interviewee AS ID,
        Interviewee.Surname,
            Interviewee.Name,
            Interviewee.Patronymic,
            Interviewee_data.Age,
            Social_statuses_codifier.Name AS Social_status,
            Gender_codifier.Name AS Gender
    FROM Interviewee_data 
    INNER JOIN Interviewee ON Interviewee_data.ID_Interviewee = Interviewee.ID
    INNER JOIN Social_statuses_codifier ON Interviewee_data.Socstat_code = Social_statuses_codifier.ID
    INNER JOIN Gender_codifier ON Interviewee_data.Gender_code = Gender_codifier.ID;';

    $createView4 = 'CREATE VIEW List_of_politicians AS
    SELECT	Politician_data.ID_Politician AS ID,
            Politician.Surname,
            Politician.Name,
            Politician.Patronymic,
            Politician_data.Age,
            Federal_subject.Name AS Federal_subject,
            Gender_codifier.Name AS Gender,
            Politician_data.Rating
    FROM Politician_data
    INNER JOIN Politician ON Politician_data.ID_Politician = Politician.ID
    INNER JOIN Federal_subject ON Politician_data.Fedsubject_code = Federal_subject.ID
    INNER JOIN Gender_codifier ON Politician_data.Gender_code = Gender_codifier.ID;';

    $createView5 = 'CREATE VIEW List_of_politicians_and_their_implemented_orders AS SELECT
    Politician.Surname,
    Politician.Name,
    Politician.Patronymic,
    Federal_subject.Name AS Federal_subject,
    Orders.Order_description AS Implemented_order
    FROM
    Politician
    LEFT JOIN Orders ON Politician.ID = Orders.ID_Politician
    INNER JOIN Politician_data ON Politician_data.ID_Politician = Politician.ID
    INNER JOIN Federal_subject ON Federal_subject.ID = Politician_data.Fedsubject_code;';
    
    $createView6 = 'CREATE VIEW Votes_of_interviewees AS
    SELECT	Interviewee.Surname AS Interviewee_surname,
        Interviewee.Name AS Interviewee_name,
            Interviewee.Patronymic AS Interviewee_patronymic,
            Politician.Surname AS Politician_surname,
            Politician.Name AS Politician_name,
            Politician.Patronymic AS Politician_patronymic,
            Poll.Politician_rating
    FROM Poll
    LEFT JOIN Interviewee_data ON Poll.ID_Interviewee = Interviewee_data.ID_Interviewee
    INNER JOIN Interviewee ON Interviewee_data.ID_Interviewee = Interviewee.ID
    LEFT JOIN Politician_data ON Poll.ID_Politician = Politician_data.ID_Politician
    INNER JOIN Politician ON Politician_data.ID_Politician = Politician.ID;';

    $createView7 = 'CREATE VIEW rating_of_politicians AS
    SELECT 	Politician_data.Rating,
            Politician.Surname,
            Politician.Name,
            Politician.Patronymic
    FROM Politician_data
    INNER JOIN Politician ON Politician_data.ID_Politician = Politician.ID';

    $createView8 = "CREATE VIEW TOP10_Politicians AS
    SELECT 	Politician_data.Rating,
            Politician.Surname,
            Politician.Name,
            Politician.Patronymic,
            CASE
                WHEN Politician_supporters.Male_support > Politician_supporters.Female_support
                    THEN 'Мужской'
                WHEN Politician_supporters.Male_support < Politician_supporters.Female_support
                    THEN 'Женский'
                ELSE 'Паритет'
            END AS Core_gender,
            CASE
                WHEN Politician_supporters.to20_support > Politician_supporters.to40_support and Politician_supporters.to20_support > Politician_supporters.to60_support and Politician_supporters.to20_support >Politician_supporters.from60_support
                    THEN 'От 16 до 20'
                WHEN Politician_supporters.to40_support > Politician_supporters.to20_support and Politician_supporters.to40_support > Politician_supporters.to60_support and Politician_supporters.to40_support >Politician_supporters.from60_support
                    THEN 'От 20 до 40'
                WHEN Politician_supporters.to60_support > Politician_supporters.to40_support and Politician_supporters.to60_support > Politician_supporters.to20_support and Politician_supporters.to60_support >Politician_supporters.from60_support
                    THEN 'От 40 до 60'
                WHEN Politician_supporters.from60_support > Politician_supporters.to40_support and Politician_supporters.from60_support > Politician_supporters.to60_support and Politician_supporters.from60_support >Politician_supporters.to20_support
                    THEN 'От 60 и выше'
                ELSE 'Паритет'
            END AS Core_age,
            CASE
                WHEN Politician_supporters.Student_support > Politician_supporters.Unemployed_support and Politician_supporters.Student_support > Politician_supporters.Employed_support and Politician_supporters.Student_support > Politician_supporters.Pensioner_support
                    THEN 'Студент/школьники'
                WHEN Politician_supporters.Unemployed_support > Politician_supporters.Student_support and Politician_supporters.Unemployed_support > Politician_supporters.Employed_support and Politician_supporters.Unemployed_support > Politician_supporters.Pensioner_support
                    THEN 'Безработные'
                WHEN Politician_supporters.Employed_support > Politician_supporters.Student_support and Politician_supporters.Employed_support > Politician_supporters.Unemployed_support and Politician_supporters.Employed_support > Politician_supporters.Pensioner_support
                    THEN 'Рабочие'
                WHEN Politician_supporters.Pensioner_support > Politician_supporters.Student_support and Politician_supporters.Pensioner_support > Politician_supporters.Employed_support and Politician_supporters.Pensioner_support > Politician_supporters.Unemployed_support
                    THEN 'Пенсионеры'
                ELSE 'Паритет'
            END AS Core_socstatus
    FROM Politician_data
    INNER JOIN Politician ON Politician_data.ID_Politician = Politician.ID
    INNER JOIN Politician_supporters ON Politician_data.ID_Politician = Politician_supporters.ID_Politician";

    $dropTable1 = 'DROP TABLE Poll;';
    $dropTable2 = 'DROP TABLE Orders;';
    $dropTable3 = 'DROP TABLE Politician_supporters';
    $dropTable4 = 'DROP TABLE Politician_data;';
    $dropTable5 = 'DROP TABLE Interviewee_data;';
    $dropTable6 = 'DROP TABLE Federal_subject;';
    $dropTable7 = 'DROP TABLE Gender_codifier;';
    $dropTable8 = 'DROP TABLE Social_statuses_codifier';
    $dropTable9 = 'DROP TABLE Politician;';
    $dropTable10 = 'DROP TABLE Interviewee;';

    $dropTrigger1 = "DROP TRIGGER update_score_after_insert;";

    $dropProcedure1 = 'DROP PROCEDURE Add_interviewee;';
    $dropProcedure2 = 'DROP PROCEDURE Delete_interviewee;';

    $dropView1 = 'DROP VIEW list_of_federal_subjects;';
    $dropView2 = 'DROP VIEW list_of_interviewees;';
    $dropView3 = 'DROP VIEW list_of_politicians;';
    $dropView4 = 'DROP VIEW list_of_politicians_and_their_implemented_orders;';
    $dropView5 = 'DROP VIEW list_of_social_statuses;';
    $dropView6 = 'DROP VIEW votes_of_interviewees;';
    $dropView7 = 'DROP VIEW rating_of_politicians;';
    $dropView8 = 'DROP VIEW TOP10_Politicians;';

    $insertData1 = 'INSERT INTO Gender_codifier VALUES (1, "Мужской"), (2, "Женский");';
    $insertData2 = 'INSERT INTO Social_statuses_codifier VALUES (1, "Школьник/студент"), (2, "Безработный"), (3, "Рабочий"),(4, "Пенсионер");';
    $insertData3 = "INSERT INTO Federal_subject
    VALUES
    (1, 'Республика Адыгея'),
    (2, 'Республика Алтай'),
    (3, 'Республика Башкортостан'),
    (4, 'Республика Бурятия'),
    (5, 'Республика Дагестан'),
    (6, 'Республика Ингушетия'),
    (7, 'Кабардино-Балкарская Республика'),
    (8, 'Республика Калмыкия'),
    (9, 'Карачаево-Черкесская Республика'),
    (10, 'Республика Карелия'),
    (11, 'Республика Коми'),
    (12, 'Республика Крым'),
    (13, 'Республика Марий Эл'),
    (14, 'Республика Мордовия'),
    (15, 'Республика Саха (Якутия)'),
    (16, 'Республика Северная Осетия — Алания'),
    (17, 'Республика Татарстан'),
    (18, 'Республика Тыва'),
    (19, 'Удмуртская Республика'),
    (20, 'Республика Хакасия'),
    (21, 'Чеченская Республика'),
    (22, 'Чувашская Республика'),
    (23, 'Алтайский край'),
    (24, 'Краснодарский край'),
    (25, 'Красноярский край'),
    (26, 'Приморский край'),
    (27, 'Ставропольский край'),
    (28, 'Хабаровский край'),
    (29, 'Амурская область'),
    (30, 'Архангельская область'),
    (31, 'Астраханская область'),
    (32, 'Белгородская область'),
    (33, 'Брянская область'),
    (34, 'Владимирская область'),
    (35, 'Волгоградская область'),
    (36, 'Вологодская область'),
    (37, 'Воронежская область'),
    (38, 'Ивановская область'),
    (39, 'Иркутская область'),
    (40, 'Калининградская область'),
    (41, 'Калужская область'),
    (42, 'Камчатский край'),
    (43, 'Кемеровская область'),
    (44, 'Кировская область'),
    (45, 'Костромская область'),
    (46, 'Курганская область'),
    (47, 'Курская область'),
    (48, 'Ленинградская область'),
    (49, 'Липецкая область'),
    (50, 'Магаданская область'),
    (51, 'Московская область'),
    (52, 'Мурманская область'),
    (53, 'Нижегородская область'),
    (54, 'Новгородская область'),
    (55, 'Новосибирская область'),
    (56, 'Омская область'),
    (57, 'Оренбургская область'),
    (58, 'Орловская область'),
    (59, 'Пензенская область'),
    (60, 'Пермский край'),
    (61, 'Псковская область'),
    (62, 'Ростовская область'),
    (63, 'Рязанская область'),
    (64, 'Самарская область'),
    (65, 'Саратовская область'),
    (66, 'Сахалинская область'),
    (67, 'Свердловская область'),
    (68, 'Смоленская область'),
    (69, 'Тамбовская область'),
    (70, 'Тверская область'),
    (71, 'Томская область'),
    (72, 'Тульская область'),
    (73, 'Тюменская область'),
    (74, 'Ульяновская область'),
    (75, 'Челябинская область'),
    (76, 'Забайкальский край'),
    (77, 'Ярославская область'),
    (78, 'город Москва'),
    (79, 'город Санкт-Петербург'),
    (80, 'Еврейская автономная область'),
    (81, 'Ненецкий автономный округ'),
    (82, 'Ханты-Мансийский автономный округ'),
    (83, 'Чукотский автономный округ'),
    (84, 'Ямало-Ненецкий автономный округ'),
    (85, 'город Севастополь'),
    (86, 'Донецкая Народная Республика'),
    (87, 'Луганская Народная Республика'),
    (88, 'Запорожская область'),
    (89, 'Херсонская область')";

    $insertData4 = "INSERT INTO Interviewee (Surname, Name, Patronymic)
    VALUES
    ('Иванов', 'Петр', 'Иванович'),
    ('Корнилова', 'Дарья', 'Леонидовна'),
    ('Сидоров', 'Сидор', 'Сидорович'),
    ('Сидорова', 'Светлана', 'Олеговна'),
    ('Николаев', 'Николай', 'Николаевич'),
    ('Андреев', 'Андрей', 'Андреевич'),
    ('Колобова', 'Светлана', 'Сергеевна'),
    ('Смирнов', 'Сергей', 'Сергеевич'),
    ('Тарасова', 'Ксения', 'Кирилловна'),
    ('Кузнецов', 'Кирилл', 'Кириллович'),
    ('Петров', 'Иван', 'Петрович'),
    ('Гробова', 'Полина', 'Петровна'),
    ('Козлов', 'Александр', ''),
    ('Степанова', 'Анастасия', 'Сергеевна'),
    ('Миронова', 'Наталья', 'Николаевна'),
    ('Леонова', 'Анна', 'Андреевна'),
    ('Норманова', 'Ольга', 'Олеговна'),
    ('Орлов', 'Олег', 'Олегович'),
    ('Михайлов', 'Михаил', 'Михайлович'),
    ('Жуков', 'Павел', 'Георгиевич')";

    $insertData5 = 'INSERT INTO Interviewee_data
    VALUES
    (1, 3, 1, 46),
    (2, 1, 2, 19),
    (3, 3, 1, 35),
    (4, 2, 2, 23),
    (5, 1, 1, 21),
    (6, 4, 1, 59),
    (7, 3, 2, 33),
    (8, 2, 1, 23),
    (9, 1, 2, 19),
    (10, 3, 1, 47),
    (11, 4, 1, 53),
    (12, 3, 2, 24),
    (13, 3, 1, 43),
    (14, 1, 2, 18),
    (15, 2, 2, 44),
    (16, 4, 2, 70),
    (17, 3, 2, 23),
    (18, 4, 1, 66),
    (19, 2, 2, 30),
    (20, 3, 1, 51)';
    
    $insertData6 = "INSERT INTO Politician (Surname, Name, Patronymic)
    VALUES
    ('Черкасова', 'Марина', 'Савельевна'),
    ('Субботин', 'Александр', 'Львович'),
    ('Маркелов', 'Евгений', 'Кириллович'),
    ('Ефремов', 'Филипп', 'Всеволодович'),
    ('Беляева', 'Александра', 'Данииловна'),
    ('Михайлова', 'Полина', 'Кирилловна'),
    ('Гусев', 'Глеб', 'Семёнович'),
    ('Некрасова', 'Александра', 'Лукинична'),
    ('Шишкин', 'Захар', 'Степанович'),
    ('Ларионова', 'Валерия', 'Георгиевна'),
    ('Ковалева', 'Анна', 'Владиславовна'),
    ('Быкова', 'Софья', 'Егоровна'),
    ('Лазарева', 'Аделина', 'Лукинична'),
    ('Успенский', 'Александр', 'Александрович'),
    ('Шишкин', 'Владимир', 'Маркович'),
    ('Лукьянова', 'Амина', 'Ивановна'),
    ('Панин', 'Александр', ''),
    ('Федосеев', 'Артём', 'Платонович'),
    ('Кузнецова', 'Василиса', 'Данииловна'),
    ('Майоров', 'Артемий', 'Егорович'),
    ('Галкина', 'Амина', 'Григорьевна'),
    ('Ермолаева', 'Злата', 'Артемьевна'),
    ('Гусева', 'Вера', 'Ярославовна'),
    ('Морозов', 'Кирилл', 'Максимович'),
    ('Попов', 'Георгий', 'Алексеевич'),
    ('Колесникова', 'Василиса', 'Ибрагимовна'),
    ('Савельев', 'Савва', 'Владиславович'),
    ('Логинов', 'Егор', 'Георгиевич'),
    ('Орлов', 'Ярослав', 'Михайлович'),
    ('Березина', 'Ксения', 'Мироновна')";

    $insertData7 = 'INSERT INTO Politician_data
    VALUES
    (1, 1, 2, 43, 0),
    (2, 1, 1, 48, 0),
    (3, 8, 1, 33, 0),
    (4, 8, 1, 41, 0),
    (5, 12, 2, 45, 0),
    (6, 12, 2, 35, 0),
    (7, 38, 1, 23, 0),
    (8, 38, 2, 33, 0),
    (9, 30, 1, 54, 0),
    (10, 30, 2, 24, 0),
    (11, 17, 2, 22, 0),
    (12, 17, 2, 29, 0),
    (13, 40, 2, 44, 0),
    (14, 40, 1, 27, 0),
    (15, 78, 1, 38, 0),
    (16, 78, 2, 53, 0),
    (17, 60, 1, 25, 0),
    (18, 60, 1, 46, 0),
    (19, 49, 2, 23, 0),
    (20, 49, 1, 28, 0),
    (21, 87, 2, 37, 0),
    (22, 87, 2, 32, 0),
    (23, 25, 2, 47, 0),
    (24, 25, 1, 23, 0),
    (25, 56, 1, 32, 0),
    (26, 26, 2, 40, 0),
    (27, 33, 1, 54, 0),
    (28, 33, 1, 35, 0),
    (29, 80, 1, 55, 0),
    (30, 80, 2, 48, 0)';

    $insertData8 = "INSERT INTO Politician_supporters
    VALUES
    (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    (30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);";

    $insertData9 = "INSERT INTO Orders
    VALUES
    (1, 'Провести расследование коррупционных случаев'),
    (1, 'Внести поправки в законодательство о прозрачности финансовых операций'),
    (2, 'Предложить новую стратегию борьбы с бедностью'),
    (3, 'Провести анализ эффективности программы социальной защиты'),
    (3, 'Предложить меры по сокращению бюрократии в государственных учреждениях'),
    (4, 'Разработать план по защите окружающей среды'),
    (4, 'Представить план по развитию цифровой инфраструктуры'),
    (6, 'Подготовить законопроект о реформе системы образования'),
    (7, 'Предложить новые меры по борьбе с наркоторговлей'),
    (7, 'Провести открытый диалог с молодежью на тему образования и карьеры'),
    (9, 'Провести аудит использования государственных средств в своем ведомстве'),
    (10, 'Предложить изменения в налоговом законодательстве'),
    (10, 'Предложить меры по улучшению условий труда для медицинских работников'),
    (10, 'Представить план по улучшению условий жизни в сельской местности'),
    (11, 'Представить отчет о выполненных обязанностях за последний год'),
    (11, 'Провести анализ эффективности программы поддержки малого и среднего бизнеса'),
    (12, 'Разработать стратегию противодействия коррупции в местном самоуправлении'),
    (12, 'Подготовить законопроект о защите прав потребителей'),
    (13, 'Провести консультации с экспертами по вопросам международной политики'),
    (13, 'Представить план по сокращению бюрократии в образовательной сфере'),
    (14, 'Представить отчет о финансовой деятельности партии за последний квартал'),
    (14, 'Провести общественные слушания по вопросам экологии'),
    (15, 'Предложить меры по поддержке предпринимательства'),
    (16, 'Провести открытый диалог с избирателями на тему экологических проблем'),
    (17, 'Представить законопроект о реформе системы здравоохранения'),
    (18, 'Подготовить аналитический отчет о состоянии общественной безопасности'),
    (20, 'Предложить меры по снижению безработицы в регионе'),
    (20, 'Предложить меры по борьбе с нелегальной миграцией'),
    (20, 'Провести анализ эффективности программы государственной поддержки семей'),
    (21, 'Подготовить законопроект о защите прав меньшинств'),
    (22, 'Представить план по развитию туризма в регионе'),
    (22, 'Подготовить законопроект о борьбе с дискриминацией в рабочей среде'),
    (23, 'Провести открытую дебатную площадку по вопросам молодежной политики'),
    (25, 'Подготовить законопроект о реформе пенсионной системы'),
    (26, 'Представить отчет о выполненных обязанностях по контролю за бюджетными средствами'),
    (27, 'Провести анализ эффективности государственных программ поддержки предпринимательства'),
    (27, 'Провести анализ эффективности программы поддержки культурных исследований'),
    (28, 'Представить план по модернизации инфраструктуры'),
    (28, 'Подготовить законопроект о реформе системы социального обеспечения'),
    (30, 'Провести консультации с общественными организациями по вопросам социальной политики');";

    $insertData10 = 'INSERT INTO Poll (ID_Interviewee, ID_Politician, Politician_rating)
    VALUES
    (1, 1, 5), (1, 2, 4), (1, 3, 3), (1, 4, 2), (1, 5, 1),
    (2, 6, 5), (2, 7, 4), (2, 8, 3), (2, 9, 2), (2, 10, 1),
    (3, 11, 5), (3, 12, 4), (3, 13, 3), (3, 14, 2), (3, 15, 1),
    (4, 16, 5), (4, 17, 4), (4, 18, 3), (4, 19, 2), (4, 20, 1),
    (5, 21, 5), (5, 22, 4), (5, 23, 3), (5, 24, 2), (5, 25, 1),
    (6, 26, 5), (6, 27, 4), (6, 28, 3), (6, 29, 2), (6, 30, 1),
    (7, 1, 5), (7, 6, 4), (7, 11, 3), (7, 16, 2), (7, 21, 1),
    (8, 2, 5), (8, 7, 4), (8, 12, 3), (8, 17, 2), (8, 22, 1),
    (9, 3, 5), (9, 8, 4), (9, 13, 3), (9, 18, 2), (9, 23, 1),
    (10, 4, 5), (10, 9, 4), (10, 14, 3), (10, 19, 2), (10, 24, 1),
    (11, 5, 5), (11, 10, 4), (11, 15, 3), (11, 20, 2), (11, 25, 1),
    (12, 1, 5), (12, 11, 4), (12, 21, 3), (12, 6, 2), (12, 16, 1),
    (13, 2, 5), (13, 12, 4), (13, 22, 3), (13, 7, 2), (13, 17, 1),
    (14, 3, 5), (14, 13, 4), (14, 23, 3), (14, 8, 2), (14, 18, 1),
    (15, 4, 5), (15, 14, 4), (15, 24, 3), (15, 9, 2), (15, 19, 1),
    (16, 5, 5), (16, 15, 4), (16, 25, 3), (16, 10, 2), (16, 20, 1),
    (17, 6, 5), (17, 16, 4), (17, 21, 3), (17, 11, 2), (17, 1, 1),
    (18, 7, 5), (18, 17, 4), (18, 22, 3), (18, 12, 2), (18, 2, 1),
    (19, 8, 5), (19, 18, 4), (19, 23, 3), (19, 13, 2), (19, 3, 1),
    (20, 9, 5), (20, 19, 4), (20, 24, 3), (20, 14, 2), (20, 4, 1);';

    if (isset($_POST['base']))
    {
        switch ($_POST['base'])
        {
            case 1:
                $sql->query($createTable1);
                $sql->query($createTable2);
                $sql->query($createTable3);
                $sql->query($createTable4);
                $sql->query($createTable5);
                $sql->query($createTable6);
                $sql->query($createTable7);
                $sql->query($createTable8);
                $sql->query($createTable9);
                $sql->query($createTable10);

                $sql->query($createTrigger1);

                $sql->query($createProcedure1);
                $sql->query($createProcedure2);

                $sql->query($createView1);
                $sql->query($createView2);
                $sql->query($createView3);
                $sql->query($createView4);
                $sql->query($createView5);
                $sql->query($createView6);
                $sql->query($createView7);
                $sql->query($createView8);
                
                
                echo "<p>Таблицы, триггер, процедуры и представления успешно созданы!</p>";
                break;

            case 2:
                $sql->query($dropTable1);
                $sql->query($dropTable2);
                $sql->query($dropTable3);
                $sql->query($dropTable4);
                $sql->query($dropTable5);
                $sql->query($dropTable6);
                $sql->query($dropTable7);
                $sql->query($dropTable8);
                $sql->query($dropTable9);
                $sql->query($dropTable10);

                $sql->query($dropTrigger1);

                $sql->query($dropProcedure1);
                $sql->query($dropProcedure2);

                $sql->query($dropView1);
                $sql->query($dropView2);
                $sql->query($dropView3);
                $sql->query($dropView4);
                $sql->query($dropView5);
                $sql->query($dropView6);
                $sql->query($dropView7);
                $sql->query($dropView8);

                echo "<p>Таблицы, триггер, процедуры и представления успешно удалены!</p>";
                break;
            
            case 3:
                $sql->query($insertData1);
                $sql->query($insertData2);
                $sql->query($insertData3);
                $sql->query($insertData4);
                $sql->query($insertData5);
                $sql->query($insertData6);
                $sql->query($insertData7);
                $sql->query($insertData8);
                $sql->query($insertData9);
                $sql->query($insertData10);

                echo "<p>Тестовые данные успешно импортированы!</p>";
                break;
        }
    }

    if (isset($_POST['interviewee']))
    {
        switch ($_POST['interviewee'])
        {
            case 1:
                ?>
                <html>
                    <form class = 'addMenu' action = "queries2.php" method="post" id = "form" style = "width: 40%; height: 30%; display:flex; border: 3px solid black;">
                        <div style = 'justify-content: center; align-items: center; width: 50%;'>
                            <p>Data of interviewee</p>
                            <input style = "width: 100%; height: 25px; margin-bottom: 10px;" type = 'text' name = 'surname' placeholder="Enter surname" maxlength="20"/>
                            <input style = "width: 100%; height: 25px;margin-bottom: 10px;" type = 'text' name = 'name' placeholder="Enter name" maxlength="20"/>
                            <input style = "width: 100%; height: 25px;margin-bottom: 10px;" type = 'text' name = 'patronymic' placeholder="Enter patronymic" maxlength="20"/>
                            <select name = 'genderlist' style = "width: 100%; height: 25px; margin-bottom: 10px;">
                                <option value="1">Мужской</option>
                                <option value="2">Женский</option>
                            </select> 
                            <select name = 'socstatlist' style = "width: 100%; height: 25px; margin-bottom: 10px;">
                                <option value="1">Школьник/студент</option>
                                <option value="2">Резработный</option>
                                <option value="3">Рабочий</option>
                                <option value="4">Пенсионер</option>
                            </select> 
                            <input style = "width: 100%; height: 25px;" type = 'number' name = 'age' placeholder="Enter age"/>
                        </div>
                        <div style = 'justify-content: center; align-items: center; width: 50%;'>
                            <p>Votes of interviewee (1 to 5)</p>
                            <select name = '1stpolitician'>
                                <?php
                                $result = $sql->query('SELECT * FROM list_of_politicians ORDER BY ID ASC');
                                while ($row = mysqli_fetch_array($result))
                                {
                                    $id = $row['ID'];
                                    $surname = $row['Surname'];
                                    $name = $row['Name'];
                                    $patronymic = $row['Patronymic'];
                                    
                                    echo "<option value = " . $id . ">" . "$surname $name $patronymic" . "</option>";
                                };
                                ?>
                            </select>
                            <select name = '2ndpolitician'>
                                <?php
                                $result = $sql->query('SELECT * FROM list_of_politicians ORDER BY ID ASC');
                                while ($row = mysqli_fetch_array($result))
                                {
                                    $id = $row['ID'];
                                    $surname = $row['Surname'];
                                    $name = $row['Name'];
                                    $patronymic = $row['Patronymic'];
                                    
                                    echo "<option value = " . $id . ">" . "$surname $name $patronymic" . "</option>";
                                };
                                ?>
                            </select>
                            <select name = '3rdpolitician'>
                                <?php
                                $result = $sql->query('SELECT * FROM list_of_politicians ORDER BY ID ASC');
                                while ($row = mysqli_fetch_array($result))
                                {
                                    $id = $row['ID'];
                                    $surname = $row['Surname'];
                                    $name = $row['Name'];
                                    $patronymic = $row['Patronymic'];
                                    
                                    echo "<option value = " . $id . ">" . "$surname $name $patronymic" . "</option>";
                                };
                                ?>
                            </select>
                            <select name = '4thpolitician'>
                                <?php
                                $result = $sql->query('SELECT * FROM list_of_politicians ORDER BY ID ASC');
                                while ($row = mysqli_fetch_array($result))
                                {
                                    $id = $row['ID'];
                                    $surname = $row['Surname'];
                                    $name = $row['Name'];
                                    $patronymic = $row['Patronymic'];
                                    
                                    echo "<option value = " . $id . ">" . "$surname $name $patronymic" . "</option>";
                                };
                                ?>
                            </select>
                            <select name = '5thpolitician'>
                                <?php
                                $result = $sql->query('SELECT * FROM list_of_politicians ORDER BY ID ASC');
                                while ($row = mysqli_fetch_array($result))
                                {
                                    $id = $row['ID'];
                                    $surname = $row['Surname'];
                                    $name = $row['Name'];
                                    $patronymic = $row['Patronymic'];
                                    
                                    echo "<option value = " . $id . ">" . "$surname $name $patronymic" . "</option>";
                                };
                                ?>
                            </select>
                            <div style = "width: 100%; align-items:center;justify-content:center;"><button type = "submit" style = "width: 100%; height: 25px;" name = "submitAdd" value = 1 form = "form">Confirm add</button></div>
                        </div>
                    </form>
                </html>
                <?php
                break;
            case 2:
                ?>
                <html>
                    <form class = 'addMenu' action = "queries2.php" method="post" id = "form" style = "width: 30%; display:flex; border: 3px solid black;">
                        <div style = 'justify-content: center; align-items: center; width: 100%;'>
                            <p align="center">Choose interviewee</p>
                            <select name = 'interviewee' style="margin-bottom: 15px; width: 100%">
                                <?php
                                $result = $sql->query('SELECT * FROM list_of_interviewees ORDER BY ID ASC');
                                while ($row = mysqli_fetch_array($result))
                                {
                                    $id = $row['ID'];
                                    $surname = $row['Surname'];
                                    $name = $row['Name'];
                                    $patronymic = $row['Patronymic'];
                                    
                                    echo "<option value = " . $id . ">" . "$surname $name $patronymic" . "</option>";
                                };
                                ?>
                            </select>
                            <div style = "width: 100%; text-align:center"><button type = "submit" style = "width:60%; font-size: 20px; border-radius: 5px;" name = "submitDelete" value = 2 form = "form">Confirm delete</button></div>
                        </div>
                    </form>
                </html>
                <?php
                break;
        }
    }

    if (isset($_POST['show']))
    {
        switch ($_POST['show'])
        {
            case 1:
                $result = $sql->query('SELECT * FROM list_of_federal_subjects');
                if ($result = $sql->query('SELECT * FROM list_of_federal_subjects'))
                {
                    echo "<div class = 'tableDiv' style = 'max-width:20%;'>";
                    echo "<h2 style = 'text-align:center;'>View of federal subjects";
                    echo "<table>";
                    echo "<thead><tr><th style = 'width: 25px;'>ID</th><th>Name</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        echo "<tr><td style = 'width: 25px;'>" . htmlspecialchars($row['ID']) . "</td><td>" . htmlspecialchars($row['Name']) . "</td></tr>";
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;
            
            case 2:
                $result = $sql->query('SELECT * FROM list_of_social_statuses');
                if ($result = $sql->query('SELECT * FROM list_of_social_statuses'))
                {
                    echo "<div class = 'tableDiv' style = 'max-width:10%;'>";
                    echo "<h2 style = 'text-align:center;'>View of social statuses";
                    echo "<table>";
                    echo "<thead><tr><th style = 'width: 25px;'>ID</th><th>Name</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        echo "<tr><td style = 'width: 25px;'>" . htmlspecialchars($row['ID']) . "</td><td>" . htmlspecialchars($row['Name']) . "</td></tr>";
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;

            case 3:
                $result = $sql->query('SELECT * FROM list_of_interviewees ORDER BY ID ASC');
                if ($result = $sql->query('SELECT * FROM list_of_interviewees ORDER BY ID ASC'))
                {
                    echo "<div class = 'tableDiv' style = 'max-width:50%;'>";
                    echo "<h2 style = 'text-align:center;'>View of interviewees";
                    echo "<table>";
                    echo "<thead><tr><th style = 'width: 25px;'>ID</th><th>Surname</th><th>Name</th><th>Patronymic</th><th style = 'width: 25px;'>Age</th><th style = 'width: 100px'>Social status</th><th style = 'width:75px;'>Gender</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        echo "<tr><td style = 'width: 25px;'>" . htmlspecialchars($row['ID']) . "</td><td>" . htmlspecialchars($row['Surname']) . "</td><td>" . htmlspecialchars($row['Name']) . "</td><td>" . htmlspecialchars($row['Patronymic']) . "</td><td style = 'width: 25px;'>" . htmlspecialchars($row['Age']) . "</td><td style = 'width: 75px'>" . htmlspecialchars($row['Social_status']) . "</td><td>" . htmlspecialchars($row['Gender']) . "</td></tr>";
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;
            
            case 4:
                $result = $sql->query('SELECT * FROM list_of_politicians ORDER BY ID ASC');
                if ($result = $sql->query('SELECT * FROM list_of_politicians ORDER BY ID ASC'))
                {
                    echo "<div class = 'tableDiv' style = 'max-width:60%;'>";
                    echo "<h2 style = 'text-align:center;'>View of politicians";
                    echo "<table>";
                    echo "<thead><tr><th style = 'width: 25px;'>ID</th><th>Surname</th><th>Name</th><th>Patronymic</th><th style = 'width: 25px;'>Age</th><th>Federal subject</th><th style = 'width:75px;'>Gender</th><th style = 'width:50px'>Rating</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        echo "<tr><td style = 'width: 25px;'>" . htmlspecialchars($row['ID']) . "</td><td>" . htmlspecialchars($row['Surname']) . "</td><td>" . htmlspecialchars($row['Name']) . "</td><td>" . htmlspecialchars($row['Patronymic']) . "</td><td style = 'width: 25px;'>" . htmlspecialchars($row['Age']) . "</td><td>" . htmlspecialchars($row['Federal_subject']) . "</td><td>" . htmlspecialchars($row['Gender']) . "</td><td>" . htmlspecialchars($row['Rating']) . "</td></tr>";
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;
            
            case 5:
                $result = $sql->query('SELECT * FROM list_of_politicians_and_their_implemented_orders');
                if ($result = $sql->query('SELECT * FROM list_of_politicians_and_their_implemented_orders'))
                {
                    echo "<div class = 'tableDiv' style = 'max-width:80%;'>";
                    echo "<h2 style = 'text-align:center;'>View of politicians and their implemented orders";
                    echo "<table>";
                    echo "<thead><tr><th style = 'width:150px;'>Surname</th><th style = 'width:150px;'>Name</th><th style = 'width:150px;'>Patronymic</th><th style = 'width:200px;'>Federal subject</th><th>Implemented order</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        echo "<tr><td>" . htmlspecialchars($row['Surname']) . "</td><td>" . htmlspecialchars($row['Name']) . "</td><td>" . htmlspecialchars($row['Patronymic']) . "</td><td>" . htmlspecialchars($row['Federal_subject']) . "</td><td>" . htmlspecialchars($row['Implemented_order']) . "</td></tr>";
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;
            
            case 6:
                $result = $sql->query('SELECT * FROM votes_of_interviewees');
                if ($result = $sql->query('SELECT * FROM votes_of_interviewees'))
                {
                    echo "<div class = 'tableDiv' style = 'max-width:60%;'>";
                    echo "<h2 style = 'text-align:center;'>View of votes of interviewees";
                    echo "<table>";
                    echo "<thead><tr><th>Interviewee's surname</th><th>Interviewee's name</th><th>Interviewee's patronymic</th><th>Politician's surname</th><th>Politician's name</th><th>Politician's patronymic</th><th style = 'width:75px;'>Politician's rating</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        echo "<tr><td>" . htmlspecialchars($row['Interviewee_surname']) . "</td><td>" . htmlspecialchars($row['Interviewee_name']) . "</td><td>" . htmlspecialchars($row['Interviewee_patronymic']) ."</td><td>" . htmlspecialchars($row['Politician_surname']) . "</td><td>" . htmlspecialchars($row['Politician_name']) . "</td><td>" . htmlspecialchars($row['Politician_patronymic']) . "</td><td>" . htmlspecialchars($row['Politician_rating']) . "</td></tr>";
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;
            
        }
    }
    if (isset($_POST['rating']))
    {
        switch ($_POST['rating'])
        {
            case 1:
                $result = $sql->query('SELECT * FROM rating_of_politicians ORDER BY Rating DESC');
                if ($result = $sql->query('SELECT * FROM rating_of_politicians ORDER BY Rating DESC'))
                {
                    $position = 0;
                    $prevRating = 0;
                    echo "<div class = 'tableDiv' style = 'max-width:60%;'>";
                    echo "<h2 style = 'text-align:center;'>Rating of politicians";
                    echo "<table>";
                    echo "<thead><tr><th style = 'width:75px'>Position</th><th>Rating</th><th>Surname</th><th>Name</th><th>Patronymic</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        if ($row['Rating'] != $prevRating) $position++;
                        echo "<tr><td>" . $position . "</td><td>" . htmlspecialchars($row['Rating']) . "</td><td>" . htmlspecialchars($row['Surname']) . "</td><td>" . htmlspecialchars($row['Name']) . "</td><td>" . htmlspecialchars($row['Patronymic']) . "</td></tr>";
                        $prevRating = $row['Rating'];
                        
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;
            
            case 2:
                $result = $sql->query('SELECT * FROM TOP10_Politicians ORDER BY Rating DESC');
                if ($result = $sql->query('SELECT * FROM TOP10_Politicians ORDER BY Rating DESC'))
                {
                    $position = 0;
                    $prevRating = 0;
                    echo "<div class = 'tableDiv' style = 'max-width:60%;'>";
                    echo "<h2 style = 'text-align:center;'>Top-10 of politicians";
                    echo "<table>";
                    echo "<thead><tr><th style = 'width:75px'>Position</th><th>Rating</th><th>Surname</th><th>Name</th><th>Patronymic</th><th>Core_gender</th><th>Core_age</th><th>Core_socstatus</th></tr></thead>";
                    echo "<tbody>";
                    while ($row = mysqli_fetch_array($result))
                    {
                        if ($row['Rating'] != $prevRating) $position++;
                        if ($position == 11) break;
                        echo "<tr><td>" . $position . "</td><td>" . htmlspecialchars($row['Rating']) . "</td><td>" . htmlspecialchars($row['Surname']) . "</td><td>" . htmlspecialchars($row['Name']) . "</td><td>" . htmlspecialchars($row['Patronymic']) . "</td><td>" . htmlspecialchars($row['Core_gender']) . "</td><td>" . htmlspecialchars($row['Core_age']) . "</td><td>" . htmlspecialchars($row['Core_socstatus']) . "</td></tr>";
                        $prevRating = $row['Rating'];
                        
                    }
                    echo "</tbody>";
                    echo "</table>";
                    echo "</div>";
                }
                else
                {
                    echo "<p>Представление не найдено!</p>";
                }
                break;
            
        }
    }

    if(isset($_POST['exit']))
    {
        header('Location: index.php');
    }
?>
</div>
</div>