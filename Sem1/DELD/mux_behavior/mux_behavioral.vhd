library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux_behavioral is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : in  STD_LOGIC;
           d : in  STD_LOGIC;
           s0 : in  STD_LOGIC;
           s1 : in  STD_LOGIC;
           z : out  STD_LOGIC);
end mux_behavioral;

architecture Behavioral of mux_behavioral is

begin
process (a,b,c,d,s0,s1) is
begin
if (s0 ='0' and s1 = '0') then
z<= a;
elsif (s0 ='0' and s1 = '1') then
z <= b;
elsif (s0 ='1' and s1 = '0') then
z <= c;
else
z <= d;
end if;
end process;

end Behavioral;


