-- Insert Global Settings Defaults
INSERT INTO `difficulty` VALUES(1, "Easy"),
                               (2, "Normal"),
                               (3, "Hard"),
                               (4, "Suicidal");
INSERT INTO `globalsettings` VALUES(1, 2, 1, 1);

-- Insert Custom Settings Defaults
INSERT INTO `customsettings` VALUES(1, 1, 1, 0, 0, "");

-- Insert Player Information Defaults
INSERT INTO `playertype` VALUES(1, "Human"),
                               (2, "Friendly AI"),
                               (3, "Nasty AI");

INSERT INTO `controlset` VALUES(1, 1, 1, 1, 1, 1),
                               (2, 1, 1, 1, 1, 1),
                               (3, 1, 1, 1, 1, 1),
                               (4, 1, 1, 1, 1, 1);
                               
INSERT INTO `player` VALUES(1, 1, 1, 1, "Player 1"),
                           (2, 2, 2, 1, "Player 2"),
                           (3, 2, 3, 1, "Player 3"),
                           (4, 2, 4, 1, "Player 4");

