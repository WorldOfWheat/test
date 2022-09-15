module cpld2(f4m,
p10, p4, p2, p14, p13,
p7, p3, p5, p9, p15, p19, p16, p18, p6, p20, p1);

	input f4m, p10, p4, p2, p14, p13;
	output p7, p3, p5, p9, p15, p19, p16, p18, p6, p20, p1;
	wire en;
	
	assign p6 = (t == 18'h1ffff);
	assign p20 = (t == 18'h2ffff);
	assign p1 = (!p13) & (!p14);
	assign en = !(p2 & p4 & p10);
	
	reg[17:0] t;
	always@(posedge f4m)
		if (~en) t = 0;
		else t = t + (t != 18'h3ffff);
	
	reg[16:0] c;
	always@(posedge f4m)
		if (~en) c = c + 1;
	
	assign {p15, p19, p16, p18} = 
	(c[16:15] == 0) ? 4'b1110:
	(c[16:15] == 1) ? 4'b1101:
	(c[16:15] == 2) ? 4'b1011:
	4'b0111;
	
	assign {p7, p3, p5, p9} =
	({c[16:15], p2, p4, p10} == 5'b00011) ? 0:
	({c[16:15], p2, p4, p10} == 5'b00101) ? 4:
	({c[16:15], p2, p4, p10} == 5'b00110) ? 8:
	
	({c[16:15], p2, p4, p10} == 5'b01011) ? 1:
	({c[16:15], p2, p4, p10} == 5'b01101) ? 5:
	({c[16:15], p2, p4, p10} == 5'b01110) ? 9:
	
	({c[16:15], p2, p4, p10} == 5'b10011) ? 2:
	({c[16:15], p2, p4, p10} == 5'b10101) ? 6:
	
	({c[16:15], p2, p4, p10} == 5'b11011) ? 3:
	({c[16:15], p2, p4, p10} == 5'b11101) ? 7:
	0;
	
endmodule
