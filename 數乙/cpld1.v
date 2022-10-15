module cpld1(f4m, 
p3, p2, p4,
p12, p10, p8, p6, p16, p14);

	input f4m, p3, p2, p4;
	output p12, p10, p8, p6, p16, p14;
	
	reg[15:0] cnt;
	reg[1:0] sel;
	reg flag, flag2;
	
	assign {p12, p10, p8, p6} =
	(sel == 0) ? cnt[15:12]:
	(sel == 1) ? cnt[11:8]:
	(sel == 2) ? cnt[7:4]:
	cnt[3:0];
	
	assign {p16, p14} = sel;

	always@(posedge f4m) 
		if (p3)
			cnt = 0;
		else
			if (p2)
				flag = 1;
			else
				if (flag) 
				begin
					flag = 0;
					if (cnt == 16'h9999)
						cnt = 0;
					else if (cnt[11:0] == 12'h999)
						cnt = cnt + 16'h0667;
					else if (cnt[7:0] == 8'h99)
						cnt = cnt + 16'h0067;
					else if (cnt[3:0] == 4'h9)
						cnt = cnt + 16'h0007;
					else
						cnt = cnt + 1;
				end
				
	always@(posedge f4m)
		if (p4)
			flag2 = 1;
		else
			if (flag2) 
			begin
				flag2 = 0;
				sel = sel + 1;
			end

endmodule
