-- Global Settings Tables
DROP TABLE IF EXISTS `globalsettings`;
DROP TABLE IF EXISTS `difficulty`;

CREATE TABLE `globalsettings`(`id` INTEGER PRIMARY KEY,
							  `difficultyid` INTEGER NOT NULL,
							  `sound` INTEGER NOT NULL,
							  `music` INTEGER NOT NULL,
							  FOREIGN KEY(`difficultyid`) REFERENCES `difficulty`(`id`) ON DELETE RESTRICT ON UPDATE RESTRICT);

CREATE TABLE `difficulty`(`id` INTEGER PRIMARY KEY,
						  `difficulty` TEXT NOT NULL);

-- Custom Settings Tables
DROP TABLE IF EXISTS `customsettings`;

CREATE TABLE `customsettings`(`id` INTEGER PRIMARY KEY,
							  `unlimitedlives` INTEGER NOT NULL,
							  `startlevel` INTEGER NOT NULL,
							  `timelimit` INTEGER,
							  `playersremain` INTEGER,
							  `advertise` TEXT);

-- Player Data Tables
DROP TABLE IF EXISTS `player`;
DROP TABLE IF EXISTS `playertype`;
DROP TABLE IF EXISTS `controlset`;

CREATE TABLE `player`(`id` INTEGER PRIMARY KEY,
					  `playertypeid` INTEGER NOT NULL,
					  `controlsetid` INTEGER NOT NULL,
					  `enabled` INTEGER NOT NULL,
					  `name` TEXT NOT NULL,
					  FOREIGN KEY(`playertypeid`) REFERENCES `playertype`(`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
					  FOREIGN KEY(`controlsetid`) REFERENCES `controlset`(`id`) ON DELETE RESTRICT ON UPDATE RESTRICT);

CREATE TABLE `playertype`(`id` INTEGER PRIMARY KEY,
						  `typename` TEXT NOT NULL);

CREATE TABLE `controlset`(`id` INTEGER PRIMARY KEY,
						  `left` INTEGER NOT NULL,
						  `right` INTEGER NOT NULL,
						  `up` INTEGER NOT NULL,
						  `down` INTEGER NOT NULL,
						  `push` INTEGER NOT NULL);

-- Score Tables
DROP TABLE IF EXISTS `score`;
DROP TABLE IF EXISTS `highscore`;
DROP TABLE IF EXISTS `recentscore`;

CREATE TABLE `score`(`id` INTEGER PRIMARY KEY AUTOINCREMENT, 
					 `name` TEXT NOT NULL,
					 `players` INTEGER NOT NULL,
					 `level` INTEGER NOT NULL,
					 `points` INTEGER NOT NULL);

CREATE TABLE `highscore`(`id` INTEGER PRIMARY KEY AUTOINCREMENT,
						 `scoreid` INTEGER,
						 FOREIGN KEY(`scoreid`) REFERENCES `score`(`id`) ON DELETE CASCADE ON UPDATE CASCADE);

CREATE TABLE `recentscore`(`id` INTEGER PRIMARY KEY AUTOINCREMENT,
						   `scoreid` INTEGER,
						   FOREIGN KEY(`scoreid`) REFERENCES `score`(`id`) ON DELETE CASCADE ON UPDATE CASCADE);
