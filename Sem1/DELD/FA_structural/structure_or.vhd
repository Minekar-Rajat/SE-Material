
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity structure_or is
    Port ( p : in  STD_LOGIC;
           q : in  STD_LOGIC;
           r : out  STD_LOGIC);
end structure_or;

architecture stroctore_OR of structure_or is

begin
r<= p or q;

end stroctore_OR;

