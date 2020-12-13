<?php
/**
 *
 */
class Balance_model extends CI_model
{
    function get_balance($id_card) {

        $query = $this->db->query("CALL getbalance($id_card)");

        return $query->row()->Saldo;
    }
}
