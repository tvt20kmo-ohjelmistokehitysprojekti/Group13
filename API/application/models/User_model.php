<?php
/**
 *
 */
class User_model extends CI_model
{
  function get_user($id){
    $this->db->select('*');
    $this->db->from('Debit');
    if($id !== NULL) {
      $this->db->where('idTili',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_user($add_data){
    $this->db->insert('Debit',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id();
    }
    else {
      return FALSE;
    }
  }
  function update_user($id, $update_data){
    $this->db->where('idTili',$id);
    $this->db->update('Debit',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function delete_user($id){
    $this->db->where('idTili',$id);
    $this->db->delete('Debit');
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function check_login($username){
    $this->db->select('PIN');
    $this->db->from('Debit');
    $this->db->where('idTili',$username);
    return $this->db->get()->row('PIN');
  }

}
