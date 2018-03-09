
#define NUM 5
#define MAX_NUM 16
#define MAX_WIDTH 5

declare detect_button {
	input	BT[NUM];
	output	RANK_OUT[MAX_WIDTH*NUM];
	func_in reset();
}
struct RANK{
	rank[MAX_WIDTH];
};
