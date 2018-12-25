#pragma once

namespace sict {
	enum Letter {Ap = 90, A =80, Bp = 75, B = 70, Cp = 65, C = 60, Dp = 55, D = 50, F =49};


	const char* enumToStr(const sict::Letter& givenGrade) {
		switch (givenGrade)
		{
		case sict::Ap:
			return "A+";
			break;
		case sict::A:
			return "A";
			break;
		case sict::Bp:
			return "B+";
			break;
		case sict::B:
			return "B";
			break;
		case sict::Cp:
			return "C+";
			break;
		case sict::C:
			return "C";
			break;
		case sict::Dp:
			return "D+";
			break;
		case sict::D:
			return "D";
			break;
		case sict::F:
			return "F";
			break;
		default:
			return "ERROR!";
			break;
		}
	}
}