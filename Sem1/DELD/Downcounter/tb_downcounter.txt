
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY tb_downcounter IS
END tb_downcounter;
 
ARCHITECTURE behavior OF tb_downcounter IS 
 
    COMPONENT Downcounter
    PORT(
         clock : IN  std_logic;
         reset : IN  std_logic;
         count : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clock : std_logic := '0';
   signal reset : std_logic := '0';

 	--Outputs
   signal count : std_logic_vector(2 downto 0);

  
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Downcounter PORT MAP (
          clock => clock,
          reset => reset,
          count => count
        );

  
   -- Stimulus process
	  process
   begin		
	
	wait for 5 ns;
	
	clock <= not clock;
	
	
	
   end process;
	
	process
	begin
	
	reset<='1';
	
	wait for 10 ns;
	
	reset <= not reset;
	
	wait;
	
	end process;
	
  
     
END;
