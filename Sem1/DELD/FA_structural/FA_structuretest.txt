
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

 
ENTITY FA_structuretest IS
END FA_structuretest;
 
ARCHITECTURE behavior OF FA_structuretest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT FA_structure
    PORT(
         x : IN  std_logic;
         y : IN  std_logic;
         z : IN  std_logic;
         sum : OUT  std_logic;
         cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal x : std_logic := '0';
   signal y : std_logic := '0';
   signal z : std_logic := '0';

 	--Outputs
   signal sum : std_logic;
   signal cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
  
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: FA_structure PORT MAP (
          x => x,
          y => y,
          z => z,
          sum => sum,
          cout => cout
        );

   -- Clock process definitions
  
 

   -- Stimulus process
  process
   begin
x <= '0';
y <= '0';
z <= '0';
wait for 5 ns;
x <= '0';
y <= '0';
z <= '1';
wait for 5 ns;
x <= '0';
y <= '1';
z <= '0';
wait for 5 ns;
x <= '0';
y <= '1';
z <= '1';
wait for 5 ns;
x <= '1';
y <= '0';
z <= '0';
wait for 5 ns;
x <= '1';
y <= '0';
z <= '1';
wait for 5 ns;
x <= '1';
y <= '1';
z <= '0';
wait for 5 ns;
x <= '1';
y <= '1';
z <= '1';
wait for 5 ns;

   end process;

END;
