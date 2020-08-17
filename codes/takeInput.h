void takePlayer1Info(char key, int selectPos) {
	if (selectPos == Name1) {
		if (key != '\b') {
			player1.name[player1.indexN++] = key;
			player1.name[player1.indexN] = '\0';
		}
		else {
			if (player1.indexN <= 0)
				player1.indexN = 0;
			else
				player1.indexN--;
			player1.name[player1.indexN] = '\0';
		}
	}
	else if (selectPos == Roll1) {
		if (key != '\b') {
			player1.rolls[player1.indexR++] = key;
			player1.rolls[player1.indexR] = '\0';
		}
		else {
			if (player1.indexR <= 0)
				player1.indexR = 0;
			else
				player1.indexR--;
			player1.rolls[player1.indexR] = '\0';
		}
	}
}

void takePlayer2Info(char key, int selectPos) {
	if (selectPos == Name2) {
		if (key != '\b') {
			player2.name[player2.indexN++] = key;
			player2.name[player2.indexN] = '\0';
		}
		else {
			if (player2.indexN <= 0)
				player2.indexN = 0;
			else
				player2.indexN--;
			player2.name[player2.indexN] = '\0';
		}
	}
	else if (selectPos == Roll1) {
		if (key != '\b') {
			player2.rolls[player2.indexR++] = key;
			player2.rolls[player2.indexR] = '\0';
		}
		else {
			if (player2.indexR <= 0)
				player2.indexR = 0;
			else
				player2.indexR--;
			player2.rolls[player2.indexR] = '\0';
		}
	}
}
