-- Insert Global Settings Defaults
INSERT INTO `difficulty` VALUES(1, "Easy"),
                               (2, "Normal"),
                               (3, "Hard"),
                               (4, "Suicidal");

INSERT INTO `generalsettings` VALUES(1, 2, 1, 1);


-- Insert Custom Settings Defaults
INSERT INTO `customsettings` VALUES(1, 1, 1, 0, 0, "");


-- Insert Player Information Defaults
INSERT INTO `playertype` VALUES(1, "Human"),
                               (2, "Friendly AI"),
                               (3, "Nasty AI");

INSERT INTO `controlset` VALUES(1, 263, 262, 265, 264, 32),   -- Left, Right, Up,  Down, Spacebar
                               (2, 323, 329, 325, 326, 333),  -- NP3,  NP9,   NP5, NP6,  NP -
                               (3, 76,  39,  80,  59,  75),   -- L,    ',     P,   ;,    K
                               (4, 83,  70,  69,  68,  65);   -- S,    F,     E,   D,    A

INSERT INTO `player` VALUES(1, 1, 1, 1, "Player 1"),
                           (2, 2, 2, 1, "Player 2"),
                           (3, 2, 3, 1, "Player 3"),
                           (4, 2, 4, 1, "Player 4");
