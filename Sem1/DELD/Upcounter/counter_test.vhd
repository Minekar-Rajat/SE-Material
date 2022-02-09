library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity counter_test is
    Port ( clock : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           count : out  STD_LOGIC_VECTOR (2 downto 0));
end counter_test;

architecture Behavioral of counter_test is
component jk_ff is
    Port ( j : in  STD_LOGIC;
           k : in  STD_LOGIC;
           clock : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           q : out  STD_LOGIC);
end component;

signal temp: STD_LOGIC_VECTOR(2 downto 0):="000";

begin

comp1:jk_ff port map(clock => clock,reset=>reset,j=>'1',k=>'1',q=>temp(2));
--comp1: jk_ff port map('1','1',clock,reset,temp(2);
comp2:jk_ff port map(clock => not temp(2),reset=>reset,j=>'1',k=>'1',q=>temp(1));
comp3:jk_ff port map(clock => not temp(1),reset=>reset,j=>'1',k=>'1',q=>temp(0));

count(2)<= temp(0);
count(1)<= temp(1);
count(0)<= temp(2);

end Behavioral;


