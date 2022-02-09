
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity FA_structure is
    Port ( x : in  STD_LOGIC;
           y : in  STD_LOGIC;
           z : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           cout : out  STD_LOGIC);
end FA_structure;

architecture structure of FA_structure is


component structure_ha is
 Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           cout : out  STD_LOGIC);
end component;
component structure_or is
 Port ( p: in  STD_LOGIC;
           q: in  STD_LOGIC;
           r: out  STD_LOGIC);
          
end component;
signal  sum1,cout1,cout2:STD_LOGIC;
begin
comp1:structure_ha port map(x,y,sum1,cout1);
comp2:structure_ha port map(sum1,z,sum,cout2);
comp3:structure_or port map(cout1,cout2,cout);

end structure;

