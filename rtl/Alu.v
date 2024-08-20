module Alu(
  input  [8:0] io_a,
  input  [8:0] io_b,
  output [8:0] io_result
);
  assign io_result = io_a + io_b;
endmodule