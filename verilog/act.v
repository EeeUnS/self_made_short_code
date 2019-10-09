// 리플 캐리 가산기
module addern(carryin,X,Y,Z, carryout);
    parameter n = 32;
    input carryin;
    input [n-1:0] X,Y;
    output reg [n-1:0] S;
    output reg carryout;
    reg [n:0] C;
    integer k;
    
    always @(X,Y,carryin)
    begin
        C[0] = carryin;
        for(k=0; k <n,k=k+1)
        begin
            S[k] = X[k]^Y[k]^C[k];
            C[k+1] = (X[k] & Y[k]) | (X[k] & C[k]) |(Y[k] & C[k]);
        end
        carryout =C[n];
    end
endmodule

module mux2to1(w0,w1,s,f);
    input w0,w1,s;
    output f;

    assign f = s ? w1:w0;

endmodule // mux2to1

module mux4to1(w0,w1,w2,w3, S,f
);
    input w0,w1,w2,w3;
    input [1:0] S;
    output f;
   
    assign f = S[1] ? (S[0] ? w3:w2) : (S[0] ? w1:w0)
endmodule // mux4to1

module dec2to4(
    input [1:0]   W,
    input En,
    output reg [0:3] Y
);

    always @(W,En)
        case ({En,Y})
            3'b100: Y = 4'b1000;
            3'b101: Y = 4'b0100;
            3'b110: Y = 4'b0010;
            3'b111: Y = 4'b0001;
            default: Y = 4'b0000;
        endcase

endmodule // dec2to4 2to4 2진 디코더

module dec4to16(
    input [3:0] W;
    input En;
    output[0:15] Y;
);
    wire [0:3] M;

    dec2to4 Dec1 (W[3:2],M[0:3],En);
    dec2to4 Dec2 (W[1:0],Y[0:3],M[0]);
    dec2to4 Dec3 (W[1:0],Y[4:7],M[1]);
    dec2to4 Dec4 (W[1:0],Y[8:11],M[2]);
    dec2to4 Dec5 (W[1:0],Y[12:15],M[3]);

endmodule // dec4to16

module ALU(
    input [2:0] S;
    input [3:0] A,B;
    output reg [3:0] F;
);

    always @(S,A,B)
        case (S)
            0 : F = 4'b0000;
            1 : F = B-A;
            2 : F = A - B;
            3 : F = A + B;
            4 : F = A ^ B;
            5 : F = A | B;
            6 : F = A & B;
            7 : F = 4'b1111;
        endcase

endmodule // ALU
