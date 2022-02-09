
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY HA_behaviortest IS
END HA_behaviortest;
 
ARCHITECTURE behavior OF HA_behaviortest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT HA_behavior
    PORT(
         a : IN  std_logic;
         b : IN  std_logic;
         sum : OUT  std_logic;
         cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';

 	--Outputs
   signal sum : std_logic;
   signal cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
  
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: HA_behavior PORT MAP (
          a => a,
          b => b,
          sum => sum,
          cout => cout
        );

   -- Clock process definitions

    process
   begin		
     a<='0';
	  b<='0';
	  wait for 5 ns;
	   a<='0';
	  b<='1';
	  wait for 5 ns;
	   a<='1';
	  b<='0';
	  wait for 5 ns;
	   a<='1';
	  b<='1';
	  wait for 5 ns;
   end process;

END;
