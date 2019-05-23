

struct bits
{
    int bit_ele;
};


struct nibble
{
    bits nibble_ele[4];
};

struct state
{
    nibble st_ele[2][2];
};



const int SubNibbles_table[4][4]=
{
(9,4,A,B),
(D,1,8,5),
(6,2,0,3),
(C,E,F,7)
};
const int InvSubNibbles_table[4][4]=
{
{A,5,9,B},
{1,7,8,F},
{6,0,2,3},
{C,4,D,E}
};

const int C[2][2]=
{
    {1,4},
    {4,1}
};

const int InvC[2][2]=
{
    {9,2},
    {9,2}
};
//대체 , 니블 내부 변환
void SubNiibbles(int nibbles[] , int outnibbles[])// 길이 4인 배열
{

    subnibbles(nibbles ,outnibbles ,SubNibbles_table );
}

void InvSubNiibbles(int nibbles[] , int outnibbles[])// 길이 4인 배열
{
    subnibbles(nibbles ,outnibbles ,InvSubNibbles_table );
}

void subnibbles(int nibbles[] , int outnibbles[] , const int nibbles_able[])
{
     int row = nibbles[3]*2 + nibbles[2]; // 행
    int col = nibbles[1]*2 + nibbles[0]; //  열
    int num =  nibbles_able[row][col];
    outnibbles[3] = num / 8;
    num = num % 8;
    outnibbles[2] = num / 4;
    num = num % 4;
    outnibbles[1] = num / 2;
    num = num % 2;
    outnibbles[0] = num;
}

//치환 니블 교환
void ShiftRows(state in_state, state out_state)
{
    out_state.st_ele[0][0] = in_state.st_ele[0][0];
    out_state.st_ele[0][1] = in_state.st_ele[0][1];
    out_state.st_ele[1][0] = in_state.st_ele[1][1];
    out_state.st_ele[1][1] = in_state.st_ele[1][0];
}


void InvShiftRows(state in_state, state out_state)
{
    out_state.st_ele[0][0] = in_state.st_ele[0][0];
    out_state.st_ele[0][1] = in_state.st_ele[0][1];
    out_state.st_ele[1][0] = in_state.st_ele[1][1];
    out_state.st_ele[1][1] = in_state.st_ele[1][0];
}

//혼한
MixColumns

// 키-합
AddRoundKey
