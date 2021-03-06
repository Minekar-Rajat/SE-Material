
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Downcounter is
    Port ( clock : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (2 downto 0));
end Downcounter;

architecture Behavioral of Downcounter is
component jk_ff is
Port ( j : in STD_LOGIC;
k : in STD_LOGIC;
clock : in STD_LOGIC;
reset : in STD_LOGIC;
q : out STD_LOGIC);
end component;
signal temp:std_logic_vector(2 downto 0) := "000";

begin
label1 : jk_ff port map ( reset => reset, clock => clock, j => '1', k => '1', q => temp(2));
label2 : jk_ff port map (reset => reset,clock => temp(2), j => '1', k => '1', q => temp(1));
label3 : jk_ff port map ( reset => reset,clock => temp(1), j => '1', k => '1',q => temp(0));
count(2) <= temp(0);
count(1) <= temp(1);
count(0) <= temp(2);


end Behavioral;

