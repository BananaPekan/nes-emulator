typedef unsigned char byte;

#define NEGATIVE  0b10000000
#define ZERO      0b01000000
#define INTERRUPT 0b00100000
#define DECIMAL   0b00010000
#define BREAK     0b00001000
#define OVERFLOW  0b00000100
#define CARRY     0b00000010

class CPU {
public:
	CPU() {};

	void LogicalAnd(byte value) {
		byte result = accumulator & value;
		SetFlag(ZERO, !result);
		SetFlag(NEGATIVE, result & NEGATIVE);
		accumulator = result;
	}

private:
	byte memory[2048];
	int pc = 0x0;
	byte flags = 0b00000000;
	byte accumulator = 0x0;

	void SetFlag(byte flag, bool value) {
		flags = (flags & ~flag) | (value * flag);
	}

	bool GetFlag(byte flag) {
		return !!(flags & flag);
	}

	byte ReadMemory(int location) {
		return memory[location];
	}
};