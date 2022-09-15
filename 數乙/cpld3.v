module cpld3(clr, 
p19, p21, p5, p22, p7, p20,
p11, p12, p14, p15, p16, p17, p8, p4, p6);

	input clr, p19, p21, p5, p22, p7, p20;
	output p11, p12, p14, p15, p16, p17, p8, p4, p6;
	wire clk;
	
	reg ip5, ip21;
	always@(posedge p22) ip5 = p5;
	always@(posedge p22) ip21 = p21;
	
	assign clk = p20 ? ip21 & p22 : p19;
	assign p8 = p20 ? ip5 & p22 : p7;
	assign p4 = p20 ? 0 : p22;
	assign p6 = p20 ? 1 : p7;
	
	reg[5:0] hour;
	
	assign {p11, p12, p14, p15, p16, p17} = hour;
	
	always@(posedge clr or posedge clk)
		if (clr)
			hour = 0;
		else
			if (hour == 6'h23) hour = 0;
			else if (hour == 6'h19) hour = 6'h20;
			else if (hour == 6'h09) hour = 6'h10;
			else hour = hour + 1;

endmodule
