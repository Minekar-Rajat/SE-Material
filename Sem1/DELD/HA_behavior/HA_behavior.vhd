
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity HA_behavior is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           sum : out  STD_LOGIC;
           cout : out  STD_LOGIC);
end HA_behavior;

architecture Behavioral of HA_behavior is

begin
process(a,b)
begin

if(a = '0' AND b ='0') then
sum <= '0';
cout <= '0';

elsif(a = '0' AND b ='1') then
sum <= '1';
cout <= '0';

elsif(a = '1' AND b ='0') then
sum <= '1';
cout <= '0';

else

sum <= '0';
cout <= '1';

end if;
end process;

end Behavioral;

