-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1:3306
-- Время создания: Июн 10 2024 г., 17:37
-- Версия сервера: 8.0.30
-- Версия PHP: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `PoliticianRating`
--
CREATE DATABASE IF NOT EXISTS `PoliticianRating` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci;
USE `PoliticianRating`;

DELIMITER $$
--
-- Процедуры
--
CREATE DEFINER=`admin`@`localhost` PROCEDURE `Add_interviewee` (IN `si` VARCHAR(20), IN `ni` VARCHAR(20), IN `pi` VARCHAR(20), IN `socst` TINYINT UNSIGNED, IN `g` TINYINT UNSIGNED, IN `a` TINYINT UNSIGNED, IN `p1` TINYINT UNSIGNED, IN `p2` TINYINT UNSIGNED, IN `p3` TINYINT UNSIGNED, IN `p4` TINYINT UNSIGNED, IN `p5` TINYINT UNSIGNED)   BEGIN
        DECLARE i INT;
        INSERT INTO Interviewee (Surname, Name, Patronymic) VALUES (si, ni, pi);
        SELECT ID INTO i FROM Interviewee WHERE Interviewee.Surname = si LIMIT 1;
        INSERT INTO Interviewee_data VALUES (i, socst, g, a);
        INSERT INTO Poll (ID_Interviewee, ID_Politician, Politician_rating) VALUES (i, p1, 1), (i, p2, 2), (i, p3, 3), (i, p4, 4), (i, p5, 5);
    END$$

CREATE DEFINER=`admin`@`localhost` PROCEDURE `Delete_interviewee` (IN `i` TINYINT UNSIGNED)   BEGIN
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
    END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Структура таблицы `Federal_subject`
--

CREATE TABLE `Federal_subject` (
  `ID` tinyint UNSIGNED NOT NULL,
  `Name` varchar(35) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Federal_subject`
--

INSERT INTO `Federal_subject` (`ID`, `Name`) VALUES
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
(89, 'Херсонская область');

-- --------------------------------------------------------

--
-- Структура таблицы `Gender_codifier`
--

CREATE TABLE `Gender_codifier` (
  `ID` tinyint UNSIGNED NOT NULL,
  `Name` varchar(7) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Gender_codifier`
--

INSERT INTO `Gender_codifier` (`ID`, `Name`) VALUES
(1, 'Мужской'),
(2, 'Женский');

-- --------------------------------------------------------

--
-- Структура таблицы `Interviewee`
--

CREATE TABLE `Interviewee` (
  `ID` smallint UNSIGNED NOT NULL,
  `Surname` varchar(20) NOT NULL,
  `Name` varchar(20) NOT NULL,
  `Patronymic` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Interviewee`
--

INSERT INTO `Interviewee` (`ID`, `Surname`, `Name`, `Patronymic`) VALUES
(1, 'Иванов', 'Петр', 'Иванович'),
(2, 'Корнилова', 'Дарья', 'Леонидовна'),
(3, 'Сидоров', 'Сидор', 'Сидорович'),
(4, 'Сидорова', 'Светлана', 'Олеговна'),
(5, 'Николаев', 'Николай', 'Николаевич'),
(6, 'Андреев', 'Андрей', 'Андреевич'),
(7, 'Колобова', 'Светлана', 'Сергеевна'),
(8, 'Смирнов', 'Сергей', 'Сергеевич'),
(9, 'Тарасова', 'Ксения', 'Кирилловна'),
(10, 'Кузнецов', 'Кирилл', 'Кириллович'),
(11, 'Петров', 'Иван', 'Петрович'),
(12, 'Гробова', 'Полина', 'Петровна'),
(13, 'Козлов', 'Александр', ''),
(14, 'Степанова', 'Анастасия', 'Сергеевна'),
(15, 'Миронова', 'Наталья', 'Николаевна'),
(16, 'Леонова', 'Анна', 'Андреевна'),
(17, 'Норманова', 'Ольга', 'Олеговна'),
(18, 'Орлов', 'Олег', 'Олегович'),
(19, 'Михайлов', 'Михаил', 'Михайлович'),
(20, 'Жуков', 'Павел', 'Георгиевич');

-- --------------------------------------------------------

--
-- Структура таблицы `Interviewee_data`
--

CREATE TABLE `Interviewee_data` (
  `ID_Interviewee` smallint UNSIGNED NOT NULL,
  `Socstat_code` tinyint UNSIGNED NOT NULL,
  `Gender_code` tinyint UNSIGNED NOT NULL,
  `Age` tinyint UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Interviewee_data`
--

INSERT INTO `Interviewee_data` (`ID_Interviewee`, `Socstat_code`, `Gender_code`, `Age`) VALUES
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
(20, 3, 1, 51);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `list_of_federal_subjects`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `list_of_federal_subjects` (
`ID` tinyint unsigned
,`Name` varchar(35)
);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `list_of_interviewees`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `list_of_interviewees` (
`ID` smallint unsigned
,`Surname` varchar(20)
,`Name` varchar(20)
,`Patronymic` varchar(20)
,`Age` tinyint unsigned
,`Social_status` varchar(20)
,`Gender` varchar(7)
);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `list_of_politicians`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `list_of_politicians` (
`ID` tinyint unsigned
,`Surname` varchar(20)
,`Name` varchar(20)
,`Patronymic` varchar(20)
,`Age` tinyint unsigned
,`Federal_subject` varchar(35)
,`Gender` varchar(7)
,`Rating` mediumint unsigned
);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `list_of_politicians_and_their_implemented_orders`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `list_of_politicians_and_their_implemented_orders` (
`Surname` varchar(20)
,`Name` varchar(20)
,`Patronymic` varchar(20)
,`Federal_subject` varchar(35)
,`Implemented_order` varchar(100)
);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `list_of_social_statuses`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `list_of_social_statuses` (
`ID` tinyint unsigned
,`Name` varchar(20)
);

-- --------------------------------------------------------

--
-- Структура таблицы `Orders`
--

CREATE TABLE `Orders` (
  `ID_Politician` tinyint UNSIGNED NOT NULL,
  `Order_description` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Orders`
--

INSERT INTO `Orders` (`ID_Politician`, `Order_description`) VALUES
(1, 'Внести поправки в законодательство о прозрачности финансовых операций'),
(1, 'Провести расследование коррупционных случаев'),
(2, 'Предложить новую стратегию борьбы с бедностью'),
(3, 'Предложить меры по сокращению бюрократии в государственных учреждениях'),
(3, 'Провести анализ эффективности программы социальной защиты'),
(4, 'Представить план по развитию цифровой инфраструктуры'),
(4, 'Разработать план по защите окружающей среды'),
(6, 'Подготовить законопроект о реформе системы образования'),
(7, 'Предложить новые меры по борьбе с наркоторговлей'),
(7, 'Провести открытый диалог с молодежью на тему образования и карьеры'),
(9, 'Провести аудит использования государственных средств в своем ведомстве'),
(10, 'Предложить изменения в налоговом законодательстве'),
(10, 'Предложить меры по улучшению условий труда для медицинских работников'),
(10, 'Представить план по улучшению условий жизни в сельской местности'),
(11, 'Представить отчет о выполненных обязанностях за последний год'),
(11, 'Провести анализ эффективности программы поддержки малого и среднего бизнеса'),
(12, 'Подготовить законопроект о защите прав потребителей'),
(12, 'Разработать стратегию противодействия коррупции в местном самоуправлении'),
(13, 'Представить план по сокращению бюрократии в образовательной сфере'),
(13, 'Провести консультации с экспертами по вопросам международной политики'),
(14, 'Представить отчет о финансовой деятельности партии за последний квартал'),
(14, 'Провести общественные слушания по вопросам экологии'),
(15, 'Предложить меры по поддержке предпринимательства'),
(16, 'Провести открытый диалог с избирателями на тему экологических проблем'),
(17, 'Представить законопроект о реформе системы здравоохранения'),
(18, 'Подготовить аналитический отчет о состоянии общественной безопасности'),
(20, 'Предложить меры по борьбе с нелегальной миграцией'),
(20, 'Предложить меры по снижению безработицы в регионе'),
(20, 'Провести анализ эффективности программы государственной поддержки семей'),
(21, 'Подготовить законопроект о защите прав меньшинств'),
(22, 'Подготовить законопроект о борьбе с дискриминацией в рабочей среде'),
(22, 'Представить план по развитию туризма в регионе'),
(23, 'Провести открытую дебатную площадку по вопросам молодежной политики'),
(25, 'Подготовить законопроект о реформе пенсионной системы'),
(26, 'Представить отчет о выполненных обязанностях по контролю за бюджетными средствами'),
(27, 'Провести анализ эффективности государственных программ поддержки предпринимательства'),
(27, 'Провести анализ эффективности программы поддержки культурных исследований'),
(28, 'Подготовить законопроект о реформе системы социального обеспечения'),
(28, 'Представить план по модернизации инфраструктуры'),
(30, 'Провести консультации с общественными организациями по вопросам социальной политики');

-- --------------------------------------------------------

--
-- Структура таблицы `Politician`
--

CREATE TABLE `Politician` (
  `ID` tinyint UNSIGNED NOT NULL,
  `Surname` varchar(20) NOT NULL,
  `Name` varchar(20) NOT NULL,
  `Patronymic` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Politician`
--

INSERT INTO `Politician` (`ID`, `Surname`, `Name`, `Patronymic`) VALUES
(1, 'Черкасова', 'Марина', 'Савельевна'),
(2, 'Субботин', 'Александр', 'Львович'),
(3, 'Маркелов', 'Евгений', 'Кириллович'),
(4, 'Ефремов', 'Филипп', 'Всеволодович'),
(5, 'Беляева', 'Александра', 'Данииловна'),
(6, 'Михайлова', 'Полина', 'Кирилловна'),
(7, 'Гусев', 'Глеб', 'Семёнович'),
(8, 'Некрасова', 'Александра', 'Лукинична'),
(9, 'Шишкин', 'Захар', 'Степанович'),
(10, 'Ларионова', 'Валерия', 'Георгиевна'),
(11, 'Ковалева', 'Анна', 'Владиславовна'),
(12, 'Быкова', 'Софья', 'Егоровна'),
(13, 'Лазарева', 'Аделина', 'Лукинична'),
(14, 'Успенский', 'Александр', 'Александрович'),
(15, 'Шишкин', 'Владимир', 'Маркович'),
(16, 'Лукьянова', 'Амина', 'Ивановна'),
(17, 'Панин', 'Александр', ''),
(18, 'Федосеев', 'Артём', 'Платонович'),
(19, 'Кузнецова', 'Василиса', 'Данииловна'),
(20, 'Майоров', 'Артемий', 'Егорович'),
(21, 'Галкина', 'Амина', 'Григорьевна'),
(22, 'Ермолаева', 'Злата', 'Артемьевна'),
(23, 'Гусева', 'Вера', 'Ярославовна'),
(24, 'Морозов', 'Кирилл', 'Максимович'),
(25, 'Попов', 'Георгий', 'Алексеевич'),
(26, 'Колесникова', 'Василиса', 'Ибрагимовна'),
(27, 'Савельев', 'Савва', 'Владиславович'),
(28, 'Логинов', 'Егор', 'Георгиевич'),
(29, 'Орлов', 'Ярослав', 'Михайлович'),
(30, 'Березина', 'Ксения', 'Мироновна');

-- --------------------------------------------------------

--
-- Структура таблицы `Politician_data`
--

CREATE TABLE `Politician_data` (
  `ID_Politician` tinyint UNSIGNED NOT NULL,
  `Fedsubject_code` tinyint UNSIGNED NOT NULL,
  `Gender_code` tinyint UNSIGNED NOT NULL,
  `Age` tinyint UNSIGNED NOT NULL,
  `Rating` mediumint UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Politician_data`
--

INSERT INTO `Politician_data` (`ID_Politician`, `Fedsubject_code`, `Gender_code`, `Age`, `Rating`) VALUES
(1, 1, 2, 43, 16),
(2, 1, 1, 48, 15),
(3, 8, 1, 33, 14),
(4, 8, 1, 41, 13),
(5, 12, 2, 45, 11),
(6, 12, 2, 35, 16),
(7, 38, 1, 23, 15),
(8, 38, 2, 33, 14),
(9, 30, 1, 54, 13),
(10, 30, 2, 24, 7),
(11, 17, 2, 22, 14),
(12, 17, 2, 29, 13),
(13, 40, 2, 44, 12),
(14, 40, 1, 27, 11),
(15, 78, 1, 38, 8),
(16, 78, 2, 53, 12),
(17, 60, 1, 25, 11),
(18, 60, 1, 46, 10),
(19, 49, 2, 23, 9),
(20, 49, 1, 28, 4),
(21, 87, 2, 37, 12),
(22, 87, 2, 32, 11),
(23, 25, 2, 47, 10),
(24, 25, 1, 23, 9),
(25, 56, 1, 32, 5),
(26, 26, 2, 40, 5),
(27, 33, 1, 54, 4),
(28, 33, 1, 35, 3),
(29, 80, 1, 55, 2),
(30, 80, 2, 48, 1);

-- --------------------------------------------------------

--
-- Структура таблицы `Politician_supporters`
--

CREATE TABLE `Politician_supporters` (
  `ID_Politician` tinyint UNSIGNED NOT NULL,
  `Male_support` smallint UNSIGNED DEFAULT NULL,
  `Female_support` smallint UNSIGNED DEFAULT NULL,
  `to20_support` smallint UNSIGNED DEFAULT NULL,
  `to40_support` smallint UNSIGNED DEFAULT NULL,
  `to60_support` smallint UNSIGNED DEFAULT NULL,
  `from60_support` smallint UNSIGNED DEFAULT NULL,
  `Student_support` smallint UNSIGNED DEFAULT NULL,
  `Unemployed_support` smallint UNSIGNED DEFAULT NULL,
  `Employed_support` smallint UNSIGNED DEFAULT NULL,
  `Pensioner_support` smallint UNSIGNED DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Politician_supporters`
--

INSERT INTO `Politician_supporters` (`ID_Politician`, `Male_support`, `Female_support`, `to20_support`, `to40_support`, `to60_support`, `from60_support`, `Student_support`, `Unemployed_support`, `Employed_support`, `Pensioner_support`) VALUES
(1, 5, 11, 0, 11, 5, 0, 0, 0, 16, 0),
(2, 15, 0, 0, 5, 9, 1, 0, 5, 9, 1),
(3, 3, 11, 10, 1, 3, 0, 10, 1, 3, 0),
(4, 8, 5, 0, 0, 13, 0, 0, 5, 8, 0),
(5, 6, 5, 0, 0, 6, 5, 0, 0, 1, 10),
(6, 0, 16, 5, 11, 0, 0, 5, 0, 11, 0),
(7, 11, 4, 4, 4, 2, 5, 4, 4, 2, 5),
(8, 0, 14, 9, 5, 0, 0, 9, 5, 0, 0),
(9, 9, 4, 2, 0, 11, 0, 2, 2, 9, 0),
(10, 4, 3, 1, 0, 4, 2, 1, 0, 0, 6),
(11, 5, 9, 0, 14, 0, 0, 0, 0, 14, 0),
(12, 13, 0, 0, 7, 4, 2, 0, 3, 8, 2),
(13, 3, 9, 7, 5, 0, 0, 7, 2, 3, 0),
(14, 7, 4, 0, 2, 9, 0, 0, 4, 7, 0),
(15, 4, 4, 0, 1, 3, 4, 0, 0, 1, 7),
(16, 0, 12, 0, 12, 0, 0, 0, 5, 7, 0),
(17, 7, 4, 0, 6, 1, 4, 0, 6, 1, 4),
(18, 0, 10, 3, 7, 0, 0, 3, 7, 0, 0),
(19, 6, 3, 0, 2, 7, 0, 0, 3, 6, 0),
(20, 2, 2, 0, 1, 2, 1, 0, 1, 0, 3),
(21, 5, 7, 0, 12, 0, 0, 5, 0, 7, 0),
(22, 11, 0, 0, 5, 3, 3, 4, 1, 3, 3),
(23, 3, 7, 4, 6, 0, 0, 7, 3, 0, 0),
(24, 6, 3, 0, 2, 7, 0, 2, 3, 4, 0),
(25, 2, 3, 0, 1, 1, 3, 1, 0, 0, 4),
(26, 5, 0, 0, 0, 5, 0, 0, 0, 0, 5),
(27, 4, 0, 0, 0, 4, 0, 0, 0, 0, 4),
(28, 3, 0, 0, 0, 3, 0, 0, 0, 0, 3),
(29, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2),
(30, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1);

-- --------------------------------------------------------

--
-- Структура таблицы `Poll`
--

CREATE TABLE `Poll` (
  `ID_poll` smallint UNSIGNED NOT NULL,
  `ID_Interviewee` smallint UNSIGNED DEFAULT NULL,
  `ID_Politician` tinyint UNSIGNED DEFAULT NULL,
  `Politician_rating` tinyint UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Poll`
--

INSERT INTO `Poll` (`ID_poll`, `ID_Interviewee`, `ID_Politician`, `Politician_rating`) VALUES
(1, 1, 1, 5),
(2, 1, 2, 4),
(3, 1, 3, 3),
(4, 1, 4, 2),
(5, 1, 5, 1),
(6, 2, 6, 5),
(7, 2, 7, 4),
(8, 2, 8, 3),
(9, 2, 9, 2),
(10, 2, 10, 1),
(11, 3, 11, 5),
(12, 3, 12, 4),
(13, 3, 13, 3),
(14, 3, 14, 2),
(15, 3, 15, 1),
(16, 4, 16, 5),
(17, 4, 17, 4),
(18, 4, 18, 3),
(19, 4, 19, 2),
(20, 4, 20, 1),
(21, 5, 21, 5),
(22, 5, 22, 4),
(23, 5, 23, 3),
(24, 5, 24, 2),
(25, 5, 25, 1),
(26, 6, 26, 5),
(27, 6, 27, 4),
(28, 6, 28, 3),
(29, 6, 29, 2),
(30, 6, 30, 1),
(31, 7, 1, 5),
(32, 7, 6, 4),
(33, 7, 11, 3),
(34, 7, 16, 2),
(35, 7, 21, 1),
(36, 8, 2, 5),
(37, 8, 7, 4),
(38, 8, 12, 3),
(39, 8, 17, 2),
(40, 8, 22, 1),
(41, 9, 3, 5),
(42, 9, 8, 4),
(43, 9, 13, 3),
(44, 9, 18, 2),
(45, 9, 23, 1),
(46, 10, 4, 5),
(47, 10, 9, 4),
(48, 10, 14, 3),
(49, 10, 19, 2),
(50, 10, 24, 1),
(51, 11, 5, 5),
(52, 11, 10, 4),
(53, 11, 15, 3),
(54, 11, 20, 2),
(55, 11, 25, 1),
(56, 12, 1, 5),
(57, 12, 11, 4),
(58, 12, 21, 3),
(59, 12, 6, 2),
(60, 12, 16, 1),
(61, 13, 2, 5),
(62, 13, 12, 4),
(63, 13, 22, 3),
(64, 13, 7, 2),
(65, 13, 17, 1),
(66, 14, 3, 5),
(67, 14, 13, 4),
(68, 14, 23, 3),
(69, 14, 8, 2),
(70, 14, 18, 1),
(71, 15, 4, 5),
(72, 15, 14, 4),
(73, 15, 24, 3),
(74, 15, 9, 2),
(75, 15, 19, 1),
(76, 16, 5, 5),
(77, 16, 15, 4),
(78, 16, 25, 3),
(79, 16, 10, 2),
(80, 16, 20, 1),
(81, 17, 6, 5),
(82, 17, 16, 4),
(83, 17, 21, 3),
(84, 17, 11, 2),
(85, 17, 1, 1),
(86, 18, 7, 5),
(87, 18, 17, 4),
(88, 18, 22, 3),
(89, 18, 12, 2),
(90, 18, 2, 1),
(91, 19, 8, 5),
(92, 19, 18, 4),
(93, 19, 23, 3),
(94, 19, 13, 2),
(95, 19, 3, 1),
(96, 20, 9, 5),
(97, 20, 19, 4),
(98, 20, 24, 3),
(99, 20, 14, 2),
(100, 20, 4, 1);

--
-- Триггеры `Poll`
--
DELIMITER $$
CREATE TRIGGER `update_score_after_insert` AFTER INSERT ON `Poll` FOR EACH ROW BEGIN
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
        END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `rating_of_politicians`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `rating_of_politicians` (
`Rating` mediumint unsigned
,`Surname` varchar(20)
,`Name` varchar(20)
,`Patronymic` varchar(20)
);

-- --------------------------------------------------------

--
-- Структура таблицы `Social_statuses_codifier`
--

CREATE TABLE `Social_statuses_codifier` (
  `ID` tinyint UNSIGNED NOT NULL,
  `Name` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `Social_statuses_codifier`
--

INSERT INTO `Social_statuses_codifier` (`ID`, `Name`) VALUES
(1, 'Школьник/студент'),
(2, 'Безработный'),
(3, 'Рабочий'),
(4, 'Пенсионер');

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `top10_politicians`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `top10_politicians` (
`Rating` mediumint unsigned
,`Surname` varchar(20)
,`Name` varchar(20)
,`Patronymic` varchar(20)
,`Core_gender` varchar(7)
,`Core_age` varchar(12)
,`Core_socstatus` varchar(17)
);

-- --------------------------------------------------------

--
-- Дублирующая структура для представления `votes_of_interviewees`
-- (См. Ниже фактическое представление)
--
CREATE TABLE `votes_of_interviewees` (
`Interviewee_surname` varchar(20)
,`Interviewee_name` varchar(20)
,`Interviewee_patronymic` varchar(20)
,`Politician_surname` varchar(20)
,`Politician_name` varchar(20)
,`Politician_patronymic` varchar(20)
,`Politician_rating` tinyint unsigned
);

-- --------------------------------------------------------

--
-- Структура для представления `list_of_federal_subjects`
--
DROP TABLE IF EXISTS `list_of_federal_subjects`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `list_of_federal_subjects`  AS SELECT `federal_subject`.`ID` AS `ID`, `federal_subject`.`Name` AS `Name` FROM `federal_subject``federal_subject`  ;

-- --------------------------------------------------------

--
-- Структура для представления `list_of_interviewees`
--
DROP TABLE IF EXISTS `list_of_interviewees`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `list_of_interviewees`  AS SELECT `interviewee_data`.`ID_Interviewee` AS `ID`, `interviewee`.`Surname` AS `Surname`, `interviewee`.`Name` AS `Name`, `interviewee`.`Patronymic` AS `Patronymic`, `interviewee_data`.`Age` AS `Age`, `social_statuses_codifier`.`Name` AS `Social_status`, `gender_codifier`.`Name` AS `Gender` FROM (((`interviewee_data` join `interviewee` on((`interviewee_data`.`ID_Interviewee` = `interviewee`.`ID`))) join `social_statuses_codifier` on((`interviewee_data`.`Socstat_code` = `social_statuses_codifier`.`ID`))) join `gender_codifier` on((`interviewee_data`.`Gender_code` = `gender_codifier`.`ID`)))  ;

-- --------------------------------------------------------

--
-- Структура для представления `list_of_politicians`
--
DROP TABLE IF EXISTS `list_of_politicians`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `list_of_politicians`  AS SELECT `politician_data`.`ID_Politician` AS `ID`, `politician`.`Surname` AS `Surname`, `politician`.`Name` AS `Name`, `politician`.`Patronymic` AS `Patronymic`, `politician_data`.`Age` AS `Age`, `federal_subject`.`Name` AS `Federal_subject`, `gender_codifier`.`Name` AS `Gender`, `politician_data`.`Rating` AS `Rating` FROM (((`politician_data` join `politician` on((`politician_data`.`ID_Politician` = `politician`.`ID`))) join `federal_subject` on((`politician_data`.`Fedsubject_code` = `federal_subject`.`ID`))) join `gender_codifier` on((`politician_data`.`Gender_code` = `gender_codifier`.`ID`)))  ;

-- --------------------------------------------------------

--
-- Структура для представления `list_of_politicians_and_their_implemented_orders`
--
DROP TABLE IF EXISTS `list_of_politicians_and_their_implemented_orders`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `list_of_politicians_and_their_implemented_orders`  AS SELECT `politician`.`Surname` AS `Surname`, `politician`.`Name` AS `Name`, `politician`.`Patronymic` AS `Patronymic`, `federal_subject`.`Name` AS `Federal_subject`, `orders`.`Order_description` AS `Implemented_order` FROM (((`politician` left join `orders` on((`politician`.`ID` = `orders`.`ID_Politician`))) join `politician_data` on((`politician_data`.`ID_Politician` = `politician`.`ID`))) join `federal_subject` on((`federal_subject`.`ID` = `politician_data`.`Fedsubject_code`)))  ;

-- --------------------------------------------------------

--
-- Структура для представления `list_of_social_statuses`
--
DROP TABLE IF EXISTS `list_of_social_statuses`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `list_of_social_statuses`  AS SELECT `social_statuses_codifier`.`ID` AS `ID`, `social_statuses_codifier`.`Name` AS `Name` FROM `social_statuses_codifier``social_statuses_codifier`  ;

-- --------------------------------------------------------

--
-- Структура для представления `rating_of_politicians`
--
DROP TABLE IF EXISTS `rating_of_politicians`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `rating_of_politicians`  AS SELECT `politician_data`.`Rating` AS `Rating`, `politician`.`Surname` AS `Surname`, `politician`.`Name` AS `Name`, `politician`.`Patronymic` AS `Patronymic` FROM (`politician_data` join `politician` on((`politician_data`.`ID_Politician` = `politician`.`ID`)))  ;

-- --------------------------------------------------------

--
-- Структура для представления `top10_politicians`
--
DROP TABLE IF EXISTS `top10_politicians`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `top10_politicians`  AS SELECT `politician_data`.`Rating` AS `Rating`, `politician`.`Surname` AS `Surname`, `politician`.`Name` AS `Name`, `politician`.`Patronymic` AS `Patronymic`, (case when (`politician_supporters`.`Male_support` > `politician_supporters`.`Female_support`) then 'Мужской' when (`politician_supporters`.`Male_support` < `politician_supporters`.`Female_support`) then 'Женский' else 'Паритет' end) AS `Core_gender`, (case when ((`politician_supporters`.`to20_support` > `politician_supporters`.`to40_support`) and (`politician_supporters`.`to20_support` > `politician_supporters`.`to60_support`) and (`politician_supporters`.`to20_support` > `politician_supporters`.`from60_support`)) then 'От 16 до 20' when ((`politician_supporters`.`to40_support` > `politician_supporters`.`to20_support`) and (`politician_supporters`.`to40_support` > `politician_supporters`.`to60_support`) and (`politician_supporters`.`to40_support` > `politician_supporters`.`from60_support`)) then 'От 20 до 40' when ((`politician_supporters`.`to60_support` > `politician_supporters`.`to40_support`) and (`politician_supporters`.`to60_support` > `politician_supporters`.`to20_support`) and (`politician_supporters`.`to60_support` > `politician_supporters`.`from60_support`)) then 'От 40 до 60' when ((`politician_supporters`.`from60_support` > `politician_supporters`.`to40_support`) and (`politician_supporters`.`from60_support` > `politician_supporters`.`to60_support`) and (`politician_supporters`.`from60_support` > `politician_supporters`.`to20_support`)) then 'От 60 и выше' else 'Паритет' end) AS `Core_age`, (case when ((`politician_supporters`.`Student_support` > `politician_supporters`.`Unemployed_support`) and (`politician_supporters`.`Student_support` > `politician_supporters`.`Employed_support`) and (`politician_supporters`.`Student_support` > `politician_supporters`.`Pensioner_support`)) then 'Студент/школьники' when ((`politician_supporters`.`Unemployed_support` > `politician_supporters`.`Student_support`) and (`politician_supporters`.`Unemployed_support` > `politician_supporters`.`Employed_support`) and (`politician_supporters`.`Unemployed_support` > `politician_supporters`.`Pensioner_support`)) then 'Безработные' when ((`politician_supporters`.`Employed_support` > `politician_supporters`.`Student_support`) and (`politician_supporters`.`Employed_support` > `politician_supporters`.`Unemployed_support`) and (`politician_supporters`.`Employed_support` > `politician_supporters`.`Pensioner_support`)) then 'Рабочие' when ((`politician_supporters`.`Pensioner_support` > `politician_supporters`.`Student_support`) and (`politician_supporters`.`Pensioner_support` > `politician_supporters`.`Employed_support`) and (`politician_supporters`.`Pensioner_support` > `politician_supporters`.`Unemployed_support`)) then 'Пенсионеры' else 'Паритет' end) AS `Core_socstatus` FROM ((`politician_data` join `politician` on((`politician_data`.`ID_Politician` = `politician`.`ID`))) join `politician_supporters` on((`politician_data`.`ID_Politician` = `politician_supporters`.`ID_Politician`)))  ;

-- --------------------------------------------------------

--
-- Структура для представления `votes_of_interviewees`
--
DROP TABLE IF EXISTS `votes_of_interviewees`;

CREATE ALGORITHM=UNDEFINED DEFINER=`admin`@`localhost` SQL SECURITY DEFINER VIEW `votes_of_interviewees`  AS SELECT `interviewee`.`Surname` AS `Interviewee_surname`, `interviewee`.`Name` AS `Interviewee_name`, `interviewee`.`Patronymic` AS `Interviewee_patronymic`, `politician`.`Surname` AS `Politician_surname`, `politician`.`Name` AS `Politician_name`, `politician`.`Patronymic` AS `Politician_patronymic`, `poll`.`Politician_rating` AS `Politician_rating` FROM ((((`poll` left join `interviewee_data` on((`poll`.`ID_Interviewee` = `interviewee_data`.`ID_Interviewee`))) join `interviewee` on((`interviewee_data`.`ID_Interviewee` = `interviewee`.`ID`))) left join `politician_data` on((`poll`.`ID_Politician` = `politician_data`.`ID_Politician`))) join `politician` on((`politician_data`.`ID_Politician` = `politician`.`ID`)))  ;

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `Federal_subject`
--
ALTER TABLE `Federal_subject`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `Gender_codifier`
--
ALTER TABLE `Gender_codifier`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `Interviewee`
--
ALTER TABLE `Interviewee`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `Interviewee_data`
--
ALTER TABLE `Interviewee_data`
  ADD PRIMARY KEY (`ID_Interviewee`),
  ADD KEY `Socstat_code` (`Socstat_code`),
  ADD KEY `Gender_code` (`Gender_code`);

--
-- Индексы таблицы `Orders`
--
ALTER TABLE `Orders`
  ADD PRIMARY KEY (`ID_Politician`,`Order_description`);

--
-- Индексы таблицы `Politician`
--
ALTER TABLE `Politician`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `Politician_data`
--
ALTER TABLE `Politician_data`
  ADD PRIMARY KEY (`ID_Politician`),
  ADD KEY `Fedsubject_code` (`Fedsubject_code`),
  ADD KEY `Gender_code` (`Gender_code`);

--
-- Индексы таблицы `Politician_supporters`
--
ALTER TABLE `Politician_supporters`
  ADD PRIMARY KEY (`ID_Politician`);

--
-- Индексы таблицы `Poll`
--
ALTER TABLE `Poll`
  ADD PRIMARY KEY (`ID_poll`),
  ADD KEY `ID_Interviewee` (`ID_Interviewee`),
  ADD KEY `ID_Politician` (`ID_Politician`);

--
-- Индексы таблицы `Social_statuses_codifier`
--
ALTER TABLE `Social_statuses_codifier`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `Interviewee`
--
ALTER TABLE `Interviewee`
  MODIFY `ID` smallint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT для таблицы `Politician`
--
ALTER TABLE `Politician`
  MODIFY `ID` tinyint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=31;

--
-- AUTO_INCREMENT для таблицы `Poll`
--
ALTER TABLE `Poll`
  MODIFY `ID_poll` smallint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=101;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `Interviewee_data`
--
ALTER TABLE `Interviewee_data`
  ADD CONSTRAINT `interviewee_data_ibfk_1` FOREIGN KEY (`ID_Interviewee`) REFERENCES `Interviewee` (`ID`) ON DELETE CASCADE,
  ADD CONSTRAINT `interviewee_data_ibfk_2` FOREIGN KEY (`Socstat_code`) REFERENCES `Social_statuses_codifier` (`ID`),
  ADD CONSTRAINT `interviewee_data_ibfk_3` FOREIGN KEY (`Gender_code`) REFERENCES `Gender_codifier` (`ID`);

--
-- Ограничения внешнего ключа таблицы `Orders`
--
ALTER TABLE `Orders`
  ADD CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`ID_Politician`) REFERENCES `Politician` (`ID`);

--
-- Ограничения внешнего ключа таблицы `Politician_data`
--
ALTER TABLE `Politician_data`
  ADD CONSTRAINT `politician_data_ibfk_1` FOREIGN KEY (`ID_Politician`) REFERENCES `Politician` (`ID`) ON DELETE CASCADE,
  ADD CONSTRAINT `politician_data_ibfk_2` FOREIGN KEY (`Fedsubject_code`) REFERENCES `Federal_subject` (`ID`),
  ADD CONSTRAINT `politician_data_ibfk_3` FOREIGN KEY (`Gender_code`) REFERENCES `Gender_codifier` (`ID`);

--
-- Ограничения внешнего ключа таблицы `Politician_supporters`
--
ALTER TABLE `Politician_supporters`
  ADD CONSTRAINT `politician_supporters_ibfk_1` FOREIGN KEY (`ID_Politician`) REFERENCES `Politician_data` (`ID_Politician`);

--
-- Ограничения внешнего ключа таблицы `Poll`
--
ALTER TABLE `Poll`
  ADD CONSTRAINT `poll_ibfk_1` FOREIGN KEY (`ID_Interviewee`) REFERENCES `Interviewee_data` (`ID_Interviewee`) ON DELETE CASCADE,
  ADD CONSTRAINT `poll_ibfk_2` FOREIGN KEY (`ID_Politician`) REFERENCES `Politician_data` (`ID_Politician`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
