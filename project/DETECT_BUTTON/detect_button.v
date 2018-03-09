
/*Produced by NSL Core(version=20170817), IP ARCH, Inc. Thu Feb 15 02:16:14 2018
 Licensed to :EVALUATION USER*/
/*
 DO NOT USE ANY PART OF THIS FILE FOR COMMERCIAL PRODUCTS. 
*/

module detect_button ( p_reset , m_clock , BT , RANK_OUT , reset );
  input p_reset, m_clock;
  wire p_reset, m_clock;
  input [4:0] BT;
  wire [4:0] BT;
  output [24:0] RANK_OUT;
  wire [24:0] RANK_OUT;
  input reset;
  wire reset;
  reg [4:0] sync0_bt;
  reg [4:0] sync1_bt;
  reg [4:0] sync2_bt;
  wire [4:0] bt_edge;
  reg [4:0] count;
  reg [4:0] _rank_rank;
  reg [4:0] _rank_1_rank;
  reg [4:0] _rank_2_rank;
  reg [4:0] _rank_3_rank;
  reg [4:0] _rank_4_rank;
  wire _net_0;
  wire _net_1;
  wire _net_2;
  wire _net_3;
  wire _net_4;
  wire _net_5;
  wire [24:0] _net_6;
  wire [4:0] _net_7;
  wire [24:0] _net_8;
  wire [4:0] _net_9;
  wire [24:0] _net_10;
  wire [4:0] _net_11;
  wire [24:0] _net_12;
  wire [4:0] _net_13;
  wire [24:0] _net_14;
  wire [4:0] _net_15;
  wire [24:0] _net_16;

   assign  bt_edge = ((sync2_bt^sync1_bt)&(~sync2_bt));
   assign  _net_0 = ((bt_edge[0])&(~(|_rank_rank)));
   assign  _net_1 = ((bt_edge[1])&(~(|_rank_1_rank)));
   assign  _net_2 = ((bt_edge[2])&(~(|_rank_2_rank)));
   assign  _net_3 = ((bt_edge[3])&(~(|_rank_3_rank)));
   assign  _net_4 = ((bt_edge[4])&(~(|_rank_4_rank)));
   assign  _net_5 = (bt_edge != 5'b00000);
   assign  _net_6 = 25'b0000000000000000000000000;
   assign  _net_7 = _rank_rank;
   assign  _net_8 = ({(_net_6[24:5]),_net_7});
   assign  _net_9 = _rank_1_rank;
   assign  _net_10 = ({(_net_8[24:10]),_net_9,(_net_8[4:0])});
   assign  _net_11 = _rank_2_rank;
   assign  _net_12 = ({(_net_10[24:15]),_net_11,(_net_10[9:0])});
   assign  _net_13 = _rank_3_rank;
   assign  _net_14 = ({(_net_12[24:20]),_net_13,(_net_12[14:0])});
   assign  _net_15 = _rank_4_rank;
   assign  _net_16 = ({_net_15,(_net_14[19:0])});
   assign  RANK_OUT = _net_16;
always @(posedge m_clock or negedge p_reset)
  begin
if (~p_reset)
     sync0_bt <= 5'b00000;
else   sync0_bt <= BT;
end
always @(posedge m_clock or negedge p_reset)
  begin
if (~p_reset)
     sync1_bt <= 5'b00000;
else   sync1_bt <= sync0_bt;
end
always @(posedge m_clock or negedge p_reset)
  begin
if (~p_reset)
     sync2_bt <= 5'b00000;
else   sync2_bt <= sync1_bt;
end
always @(posedge m_clock or negedge p_reset)
  begin
if (~p_reset)
     count <= 5'b00000;
else if ((reset)|(_net_5)) 
      count <= ((reset) ?5'b00000:5'b0)|
    ((_net_5) ?(count+5'b00001):5'b0);

end
always @(posedge m_clock)
  begin
if ((reset)|(_net_0)) 
      _rank_rank <= ((reset) ?5'b00000:5'b0)|
    ((_net_0) ?count:5'b0);

end
always @(posedge m_clock)
  begin
if ((reset)|(_net_1)) 
      _rank_1_rank <= ((reset) ?5'b00000:5'b0)|
    ((_net_1) ?count:5'b0);

end
always @(posedge m_clock)
  begin
if ((reset)|(_net_2)) 
      _rank_2_rank <= ((reset) ?5'b00000:5'b0)|
    ((_net_2) ?count:5'b0);

end
always @(posedge m_clock)
  begin
if ((reset)|(_net_3)) 
      _rank_3_rank <= ((reset) ?5'b00000:5'b0)|
    ((_net_3) ?count:5'b0);

end
always @(posedge m_clock)
  begin
if ((reset)|(_net_4)) 
      _rank_4_rank <= ((reset) ?5'b00000:5'b0)|
    ((_net_4) ?count:5'b0);

end
endmodule

/*Produced by NSL Core(version=20170817), IP ARCH, Inc. Thu Feb 15 02:16:14 2018
 Licensed to :EVALUATION USER*/
