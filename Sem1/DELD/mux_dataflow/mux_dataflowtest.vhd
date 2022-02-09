--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:14:23 10/05/2019
-- Design Name:   
-- Module Name:   /home/del/21411/Mux_dataflow/mux_dataflowtest.vhd
-- Project Name:  Mux_dataflow
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: mux_dataflow
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
 
ENTITY mux_dataflowtest IS
END mux_dataflowtest;
 
ARCHITECTURE behavior OF mux_dataflowtest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux_dataflow
    PORT(
         a : IN  std_logic;
         b : IN  std_logic;
         c : IN  std_logic;
         d : IN  std_logic;
         s0 : IN  std_logic;
         s1 : IN  std_logic;
         y : OUT  std_logic
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
   signal y : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
  
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux_dataflow PORT MAP (
          a => a,
          b => b,
          c => c,
          d => d,
          s0 => s0,
          s1 => s1,
          y => y
        );

  

   -- Stimulus process
    process
   begin		
wait for 5 ns;

a<= '1';
b<= '0';
c<= '1';
d<= '0';

s0<= '0'; s1 <= '0';
wait for 5 ns;

s0 <= '0'; s1 <= '1';
wait for 5 ns;

s0 <= '1'; s1 <= '0';
wait for 5 ns;

s0 <= '1'; s1 <= '1';
wait for 5 ns;
   end process;

END;
