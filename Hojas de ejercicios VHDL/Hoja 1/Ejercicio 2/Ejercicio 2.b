library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity My_XOR is
port ( A : in std_logic_vector(3 downto 0);
       Y : out std_logic);
       
end entity;

Architecture Behavioral of My_XOR is
begin

Y <= A(3) xor A(2) xor A(1) xor A(0);

 end Behavioral;
 
