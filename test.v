module led_7seg (
    input clock, s1,rst,
    output [7,0] led,
    reg [7,0] led,
    reg [3,0] bcd,
   
);


always @(posedge clock)
 begin
   if (rst == 1'b1) 
        bcd <= b'b0;
    else if(s1 == 1'b1)
        bcd <= bcd + 1'b1;
    if(bcd == 4'b1001) 
        bcd <= 4'b0000;   
end

always @(posedge clock)
begin
    case(bcd)
        4'b0000: led = 8'b11111100;
        4'b0001: led = 8'b01100000;
        4'b0010: led = 8'b11011010;
        4'b0011: led = 8'b11110010;
        4'b0100: led = 8'b01100110;
        4'b0101: led = 8'b10110110;
        4'b0110: led = 8'b10111110;
        4'b0111: led = 8'b11100000;
        4'b1000: led = 8'b11111110;
        4'b1001: led = 8'b11100110;
        default: led = 8'b11111111;
    endcase


end
    
endmodule
