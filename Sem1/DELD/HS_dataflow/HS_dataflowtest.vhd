--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:54:20 10/05/2019
-- Design Name:   
-- Module Name:   /home/del/21411/HS_dataflow/HS_dataflowtest.vhd
-- Project Name:  HS_dataflow
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: HS_dataflow
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY HS_dataflowtest IS
END HS_dataflowtest;
 
ARCHITECTURE behavior OF HS_dataflowtest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT HS_dataflow
    PORT(
         a : IN  std_logic;
         b : IN  std_logic;
         diff : OUT  std_logic;
         borrow : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';

 	--Outputs
   signal diff : std_logic;
   signal borrow : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
  
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: HS_dataflow PORT MAP (
          a => a,
          b => b,
          diff => diff,
          borrow => borrow
        );

   -- Clock process definitions
 

   -- Stimulus process
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
