
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity HS_dataflow is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           diff : out  STD_LOGIC;
           borrow : out  STD_LOGIC);
end HS_dataflow;

architecture dataflow of HS_dataflow is

begin
diff<=a xor b;
borrow<=(not a) and b;

end dataflow;

