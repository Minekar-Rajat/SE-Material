LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY mux_behavioraltest IS
END mux_behavioraltest;
 
ARCHITECTURE behavior OF mux_behavioraltest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux_behavioral
    PORT(
         a : IN  std_logic;
         b : IN  std_logic;
         c : IN  std_logic;
         d : IN  std_logic;
         s0 : IN  std_logic;
         s1 : IN  std_logic;
         z : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';
   signal c : std_logic := '0';
   signal d : std_logic := '0';
   signal s0 : std_logic := '0';
   signal s1 : std_logic := '0';

 	--Outputs
   signal z : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 

BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux_behavioral PORT MAP (
          a => a,
          b => b,
          c => c,
          d => d,
          s0 => s0,
          s1 => s1,
          z => z
        );

  
 

   -- Stimulus process
  process
   begin		
     wait for 5 ns;

A <= '1';
B <= '0';
C <= '1';
D <= '0';

S0 <= '0'; S1 <= '0';
wait for 5 ns;

S0 <= '0'; S1 <= '1';
wait for 5 ns;

S0 <= '1'; S1 <= '0';
wait for 5 ns;

S0 <= '1'; S1 <= '1';
wait for 5 ns;
   end process;

END;

